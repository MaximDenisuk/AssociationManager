//
// Created by mdenysiuk on 06.04.19.
//

#include "cView.h"

cView::cView(const bool _isLoggerNeeded):
        logger_(Logger()),
        msgValidator_(cMsgValidator(logger_)),
        controller_(cEntityController(logger_)) {
}


cView::~cView() {
}

void cView::startInput() {
    logger_.print(__FUNCTION__);
    // TODO: add Force save after atomic save realisation
    //                  "If you want to make force save type \"forceSave\"" << std::endl <<
    auto help = [] {
    std::cout << "Hello, this is Association Manager!" << std::endl <<
              "In this programm you are able to:" << std::endl <<
              "1) create Entity using simple command \"=\", like:" << std::endl <<
              "a = Alex " << std::endl <<
              "2) make association between entities using \"- key -\", like:" << std::endl <<
              "a - to do the best - a"<< std::endl <<
              "3) print all data related to Entity using command \"?\", like:" << std::endl <<
              "a ?" << std::endl <<
              "4) To see all exists entities type \"-v\"" << std:: endl <<
              "5) To generate usecase diag type \"-g uc\"" << std:: endl <<
              "6) To generate object diag type \"-g obj\"" << std:: endl <<
              "For exit type \"q\"" << std::endl <<
              "To see this msg again type \"help\"" << std::endl;
    };
    auto wrongSyntax = [] {
        std::cout << "Wrong syntax!" << std::endl;
    };

    help();

    std::string userMessage = "";
    std::vector<std::string> responseData;
    while(true) {
        std::cout << std::endl << "127.0.0.1: ";
        std::getline(std::cin, userMessage);
        if (!userMessage.empty()) {
            if (userMessage.compare("q") == 0) {
                break;
            } else if (userMessage.compare("help") == 0) {
                help();
            } else  if (userMessage.compare("-v") == 0) {
                auto result = controller_.viewEntities();
                if (commonTypes::eAMErrorTypes::NO_ERROR != result.first) {
                    std::cerr << "Fail to view entities. Smth goes wrong..." << std::endl;
                } else {
                    viewEntities(result.second);
                }
            } else  if (userMessage.compare("-g uc") == 0){
                responseData.clear();
                processControllerResponse(controller_.generateUseCaseDiagr(), responseData);
            } else  if (userMessage.compare("-g obj") == 0){
                responseData.clear();
                processControllerResponse(controller_.generateObjDiagr(), responseData);
            } else {
                // send request to inputValidator
                common::commonTypes::eMSG_PATTERN msgPattern = msgValidator_.isOneOfMsgPatterns(userMessage);
                std::vector<std::string> msgUsefullData;
                switch (msgPattern) {
                    case common::commonTypes::eMSG_PATTERN::CREATE_ENTITY: {
                        msgUsefullData =
                                msgValidator_.getMessageInfo(common::commonTypes::eMSG_PATTERN::CREATE_ENTITY,
                                                            userMessage);
                        responseData.clear();
                        processControllerResponse(controller_.createEntity(msgUsefullData), responseData);
                    }
                        break;
                    case common::commonTypes::eMSG_PATTERN::MAKE_ASSOCIATION: {
                        msgUsefullData =
                                msgValidator_.getMessageInfo(common::commonTypes::eMSG_PATTERN::MAKE_ASSOCIATION,
                                                            userMessage);
                        responseData.clear();
                        processControllerResponse(controller_.makeEnttityAssociation(msgUsefullData), responseData);
                    }
                        break;
                    case common::commonTypes::eMSG_PATTERN::VIEW_ENTITY_INFO: {
                        msgUsefullData =
                                msgValidator_.getMessageInfo(common::commonTypes::eMSG_PATTERN::VIEW_ENTITY_INFO,
                                                            userMessage);
                        auto result = controller_.viewEntityData(msgUsefullData);
                        if (commonTypes::eAMErrorTypes::NO_ERROR != result.first) {
                            std::cerr << "Fail to view entity data. Smth goes wrong..." << std::endl;
                        } else {
                            viewEntities(result.second);
                        }
                    }
                        break;
                    default: {
                        wrongSyntax();
                    }
                }
            }
        } else {
            wrongSyntax();
        }
    }
}

void cView::start() {
    startInput();
}

void cView::processControllerResponse(const commonTypes::eAMErrorTypes &_error, std::vector<std::string> &_data) {
    switch(_error) {
        case commonTypes::eAMErrorTypes::NO_ERROR: {
            actionComplete();
        }
            break;
        case commonTypes::eAMErrorTypes::ERROR_SAVE_DATA: {
            errorSaveData();
        }
            break;
        case commonTypes::eAMErrorTypes::ERROR_ENTITY_ALREADY_EXISTS: {
            std::string entityName = "";
            if(!_data.empty()) {
                entityName = _data[0];
            }
            errorEntityAlreadyExists(entityName);
        }
            break;
        case commonTypes::eAMErrorTypes::ERROR_ENTITY_NOT_FOUND: {
            std::string entityName = "";
            if(!_data.empty()) {
                entityName = _data[0];
            }
            errorEntityNotFound(entityName);
        }
            break;
        case commonTypes::eAMErrorTypes::ERROR_ASSOCIATION_ALREADY_EXISTS: {
            auto association = std::pair<std::string, std::string>("", "");
            if(_data.size() == 2) {
                association = std::pair<std::string, std::string>(_data[0], _data[1]);
            }
            errorAssociationAlreadyExists(association);
        }
            break;
        case commonTypes::eAMErrorTypes::ERROR_CORRUPTED_ENTITY_NAMES: {
            errorCorruptedEntityNames();
        }
            break;
        case commonTypes::eAMErrorTypes::ERROR_DIAG_GENERATION_FAILED: {
            errorDiagGenerationFailed();
        }
            break;
        default: {
            std::cerr << "Unknown controller error!" << std::endl;
        }
            break;
    }
}

void cView::viewEntityInfo(const std::vector<std::pair<std::string, std::string>> &_entityDataToShow) {
    if (!_entityDataToShow.empty()) {
        std::string entityName;
        if (!_entityDataToShow[0].second.empty()) {
            entityName = _entityDataToShow[0].second;
        } else if (!_entityDataToShow[0].first.empty()) {
            entityName = _entityDataToShow[0].first;
        }
        std::cout << "Entity name is: " << entityName << std::endl;
        std::cout << "Assotiacions list: " << std::endl;
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

void cView::errorCorruptedEntityNames() {
    std::cout << "Entity names are corrupted. Please edit them before entity use!" << std::endl;
}

void cView::errorEntityNotFound(const std::string &_entityName) {
    std::cout << "Mentiont entity " << _entityName << " doesn't exists !" << std::endl;
}

void cView::errorEntityAlreadyExists(const std::string &_entityName) {
    std::cout << "Mentiont entity short-name " << _entityName << " already exists!" << std::endl;
}

void cView::viewEntities(const std::vector<std::pair<std::string, std::string>> &_entityNames) {
    if (!_entityNames.empty()) {
        std::cout << "Exists entities: " << std::endl;
        for (const auto names : _entityNames) {
            std::cout << names.first << " = " << names.second << std::endl;
        }
    } else {
        std::cout << "No data to show" << std::endl;
    }
}

void cView::errorAssociationAlreadyExists(const std::pair<std::string, std::string> &_association) {
    if (!_association.first.empty() && !_association.second.empty()) {
        std::cout << "Association \""
            << _association.first
            << "\" already exists and points to \""
            << _association.second
            << "\""
            << std::endl;
    }
}

void cView::actionComplete() {
    std::cout << "Complete !" << std::endl;
}

void cView::errorSaveData() {
    std::cout << "Storage error. Storage didn't save data! Is force save needed?" << std::endl;
}

void cView::errorDiagGenerationFailed() {
    std::cout << "Diag generation is failed." << std::endl;
}

