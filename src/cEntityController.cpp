//
// Created by mdenysiuk on 03.04.19.
//

#include <algorithm>
#include "cEntityController.h"

//TODO: Find solution aout how to share cView to controller
//cEntityController::cEntityController(Logger &_logger, cView &_viewer):
//    logger_(_logger),
//    viewer_(_viewer),
//    storage_(logger_) {
//    logger_.print("cEntityController ctor");
//}

cEntityController::cEntityController(Logger &_logger):
        logger_(_logger),
        storage_(logger_) {
    logger_.print("cEntityController ctor");
}

void cEntityController::createEntity(const std::vector<std::string> &_msgData) {
    logger_.print(__FUNCTION__);
    if (!_msgData.empty() && constants::CREATE_ENTITY_MAX_PARAMS_COUNT == _msgData.size()){
        // TODO: release logic of createEntity
        const std::string shortName = _msgData[0],
                          longName = _msgData[1];
        if (!shortName.empty() && !longName.empty()) {
            auto pFoundEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(shortName) == 0;
            });
            if (pFoundEntity == entitiesList_.end()) {
                cEntity entity(shortName, longName);
                entitiesList_.push_back(entity);
                storage_.saveData(entitiesList_);
            } else {
                tmpEntityAlreadyExists(shortName);
            }

        } else {
            logger_.printError(__FUNCTION__, "Wrong incomming data. Short or long name are empty");
        }
    } else {
        logger_.printError(__FUNCTION__, "Wrong incomming data. It is empty or wrong size");
    }
}
void cEntityController::makeEnttityAssociation(const std::vector<std::string> &_msgData) {
    logger_.print(__FUNCTION__);
    if (!_msgData.empty() && constants::MAKE_ASSOCIATION_MAX_PARAMS_COUNT  == _msgData.size()){
        auto pFoundEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(_msgData[0]) == 0;
            });
        if (pFoundEntity != entitiesList_.end() && !_msgData[1].empty() && !_msgData[2].empty()) {
            const auto kPAssociationTargetEntity = std::find_if(entitiesList_.begin(), entitiesList_.end(), [=] (cEntity _entity) {
                return _entity.getShortName_().compare(_msgData[2]) == 0;
            });
            if (kPAssociationTargetEntity != entitiesList_.end()) {
                pFoundEntity->addAssociation(_msgData[1], _msgData[2]);
                storage_.saveData(entitiesList_);
                logger_.print(__FUNCTION__, "Association added");
            } else {
//                viewer_.viewEntityInfo(dataToShow);
                tmpEntityNotFoundError(_msgData[2]);
            }
        } else {
            logger_.print(__FUNCTION__, "Entity with this name not found, create it at first, name: ", _msgData[0].c_str());
        }
    } else {
        logger_.printError(__FUNCTION__, "Wrong incomming data. It is empty or wrong size");
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
//                    viewer_.viewEntityInfo(dataToShow);
                    tmpViewEntityInfo(dataToShow);
                }
            } else {
                logger_.printError(__FUNCTION__, "One of entity names are empty");
            }
        } else {
            logger_.print(__FUNCTION__, "Entity with this name not found, create it at first, name: ", _msgData[0].c_str());
        }
    } else {
        logger_.printError(__FUNCTION__, "Wrong incomming data. It is empty or wrong size");
    }
}

void cEntityController::tmpViewEntityInfo(const std::vector<std::pair<std::string, std::string>> &_entityDataToShow) {
    //    std::cout << "\t:" << association.first << " -> " << association.second << std::endl;
    if (!_entityDataToShow.empty()) {
        std::string entityName;
        if (!_entityDataToShow[0].second.empty()) {
            entityName = _entityDataToShow[0].second;
        } else if (!_entityDataToShow[0].first.empty()) {
            entityName = _entityDataToShow[0].first;
        }
        std::cout << "Entity name is: " << entityName << std::endl;
        std::cout << "Assotiacions list: " << std::endl;
//        for (std::iterator it = _entityDataToShow.begin()+1;; )
        for(std::vector<std::pair<std::string, std::string>>::const_iterator itAssotioation = _entityDataToShow.begin()+1;
            itAssotioation != _entityDataToShow.end();
            ++itAssotioation) {
            if (!itAssotioation->first.empty() && !itAssotioation->second.empty()) {
                std::cout << "\t: " << itAssotioation->first << " --> " << itAssotioation->second << std::endl;
            }
        }

    } else {
        logger_.printError(__FUNCTION__, "Data to show is empty");
    }
}

void cEntityController::tmpEntityNotFoundError(const std::string &_entityName) {
    if ( !_entityName.empty()) {
        std::cout << "Mentiont entity \"" << _entityName << "\" doesn't exists !" << std::endl;
    } else {
        logger_.printError(__FUNCTION__, "Data to show is empty");
    }
}

void cEntityController::tmpEntityAlreadyExists(const std::string &_entityName) {
    if ( !_entityName.empty()) {
        std::cout << "Mentiont entity short-name \"" << _entityName << "\" already exists!" << std::endl;
    } else {
        logger_.printError(__FUNCTION__, "Data to show is empty");
    }
}