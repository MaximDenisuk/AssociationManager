//
// Created by mdenysiuk on 03.04.19.
//

#include <algorithm>
#include "../cEntityController.h"
#include "../../src/cView.h"


cEntityController::cEntityController(Logger &_logger, cView &_viewer):
    logger_(_logger),
    viewer_(_viewer),
    storage_(_logger,*this) {
    logger_.print("cEntityController ctor");
    if (commonTypes::eSTATUS::COMPLETE != storage_.requestLoadFullData()) {
        viewer_.errorLoadData();
    }
}

void cEntityController::responseLoadFullData() {
    logger_.print(__FUNCTION__);
    entitiesList_ = storage_.getStoredEntities_();
}

void cEntityController::createEntity(const std::vector<std::string> &_msgData) {
    logger_.print(__FUNCTION__);
    if (!_msgData.empty() && constants::CREATE_ENTITY_MAX_PARAMS_COUNT == _msgData.size()){
        const std::string shortName = _msgData[0],
                          longName = _msgData[1];
        if (!shortName.empty() && !longName.empty()) {
            auto pFoundEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(shortName) == 0;
            });
            if (pFoundEntity == entitiesList_.end()) {
                cEntity entity(shortName, longName);
                entitiesList_.push_back(entity);
                if (commonTypes::eSTATUS::COMPLETE != storage_.requestSaveFullData(entitiesList_)) {
                    viewer_.errorSaveData();
                }
            } else {
                viewer_.errorEntityAlreadyExists(shortName);
            }

        } else {
            viewer_.errorEntityNotFound("");
            logger_.printError(__FUNCTION__, "Wrong incomming data. Short or long name are empty");
        }
    } else {
        viewer_.errorEntityNotFound("");
        logger_.printError(__FUNCTION__, "Wrong incomming data count");
    }
}
void cEntityController::makeEnttityAssociation(const std::vector<std::string> &_msgData) {
    logger_.print(__FUNCTION__);
    if (!_msgData.empty() && constants::MAKE_ASSOCIATION_MAX_PARAMS_COUNT  == _msgData.size()) {
        auto pFoundEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(_msgData[0]) == 0;
            });
        if (pFoundEntity != entitiesList_.end() && !_msgData[1].empty() && !_msgData[2].empty()) {
            const auto kPAssociationTargetEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(_msgData[2]) == 0;
            });
            if (kPAssociationTargetEntity != entitiesList_.end()) {
                const auto isThisAssociationNotExists = std::find_if(pFoundEntity->getAssociationList().begin(),
                                                                     pFoundEntity->getAssociationList().end(),
                                                                     [=] (std::pair<std::string, std::string> _names) {
                     return 0 == _names.first.compare(_msgData[1]) &&  0 == _names.second.compare(_msgData[2]);
                });
                if (isThisAssociationNotExists == pFoundEntity->getAssociationList().end()) {
                    pFoundEntity->addAssociation(_msgData[1], _msgData[2]);
                    if (commonTypes::eSTATUS::COMPLETE != storage_.requestSaveFullData(entitiesList_)) {
                        viewer_.errorSaveData();
                    }
                    logger_.print(__FUNCTION__, "Association added");
                } else {
                    viewer_.errorAssociationAlreadyExists(*isThisAssociationNotExists);
                    logger_.printError(__FUNCTION__, "Error association already exists");
                }
            } else {
                viewer_.errorEntityNotFound(_msgData[2].c_str());
                logger_.printError(__FUNCTION__, "Entity not found - ", _msgData[2].c_str());
            }
        } else {
            viewer_.errorEntityNotFound(_msgData[0].c_str());
            logger_.printError(__FUNCTION__, "Entity not found - ", _msgData[0].c_str());
        }
    } else {
        viewer_.errorEntityNotFound("");
        logger_.printError(__FUNCTION__, "Wrong incomming data count");
    }
}
void cEntityController::viewEntityData(const std::vector<std::string> &_msgData) {
    logger_.print(__FUNCTION__);
    if (!_msgData.empty() && constants::VIEW_ENTITY_MAX_PARAMS_COUNT == _msgData.size()){
        const auto kPFoundEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(_msgData[0]) == 0;
            });
        if (kPFoundEntity != entitiesList_.end()) {
            std::vector<std::pair<std::string, std::string>> dataToShow;
            std::string entityName;
            if (!kPFoundEntity->getLongName_().empty() && !kPFoundEntity->getShortName_().empty()) {
                dataToShow.push_back(std::pair<std::string, std::string>(kPFoundEntity->getShortName_(), kPFoundEntity->getLongName_()));
                for (const auto association : kPFoundEntity->getAssociationList()) {
                    dataToShow.push_back(std::pair<std::string, std::string>(association.first, association.second));
                }
                if (!dataToShow.empty()) {
                    viewer_.viewEntityInfo(dataToShow);
                }
            } else {
                viewer_.errorCorruptedEntityNames();
                logger_.printError(__FUNCTION__, "One of entity names are empty");
            }
        } else {
            viewer_.errorEntityNotFound(_msgData[0].c_str());
            logger_.print(__FUNCTION__, "Entity with this name not found - ", _msgData[0].c_str());
        }
    } else {
        viewer_.errorEntityNotFound("");
        logger_.printError(__FUNCTION__, "Wrong incomming data count");
    }
}

void cEntityController::viewEntities() {
    logger_.print(__FUNCTION__);
    std::vector<std::pair<std::string, std::string>> entityNames;
    for (const auto entity : entitiesList_) {
        entityNames.push_back(std::pair<std::string, std::string>(entity.getShortName_(), entity.getLongName_()));
    }
    viewer_.viewEntities(entityNames);
}

void cEntityController::generateUseCaseDiagr() {
    logger_.print(__FUNCTION__);
    commonTypes::eSTATUS genResult = storage_.generateUseCaseDiagr(entitiesList_);
    if (commonTypes::eSTATUS::COMPLETE != genResult) {
        viewer_.errorDiagGenerationFailed();
    } else {
        viewer_.actionComplete();
    }
}

void cEntityController::generateObjDiagr() {
    logger_.print(__FUNCTION__);
    commonTypes::eSTATUS genResult = storage_.generateObjectDiagr(entitiesList_);
    if (commonTypes::eSTATUS::COMPLETE != genResult) {
        viewer_.errorDiagGenerationFailed();
    } else {
        viewer_.actionComplete();
    }
}
