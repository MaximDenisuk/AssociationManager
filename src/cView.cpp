//
// Created by mdenysiuk on 06.04.19.
//

#include "cView.h"

cView::cView(const bool _isLoggerNeeded):
        logger_(Logger()),
        msgValidator_(cMsgValidator(logger_)),
        controller_(cEntityController(logger_, *this)) {
}


cView::~cView() {
}

void cView::startInput() {
    logger_.print(__FUNCTION__);
    // TODO: add Force save after atomic save realisation
    //                  "If you want to make force save type \"forceSave\"" << std::endl <<
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
    auto help = [] {
    };
    auto wrongSyntax = [] {
        std::cout << "Wrong syntax!" << std::endl;
    };

    help();

    std::string userMessage = "";
    while(true) {
        std::getline(std::cin, userMessage);
        if (!userMessage.empty()) {
            if (userMessage.compare("q") == 0) {
                break;
            } else if (userMessage.compare("help") == 0) {
                help();
            } else  if (userMessage.compare("-v") == 0){
                controller_.viewEntities();
            } else  if (userMessage.compare("-g uc") == 0){
                controller_.generateUseCaseDiagr();
            } else  if (userMessage.compare("-g obj") == 0){
                controller_.generateObjDiagr();
            } else {
                // send request to inputValidator
                common::commonTypes::eMSG_PATTERN msgPattern = msgValidator_.isOneOfMsgPatterns(userMessage);
                std::vector<std::string> msgUsefullData;
                switch (msgPattern) {
                    case common::commonTypes::eMSG_PATTERN::CREATE_ENTITY: {
                        msgUsefullData =
                                msgValidator_.getMessageInfo(common::commonTypes::eMSG_PATTERN::CREATE_ENTITY,
                                                            userMessage);
                        controller_.createEntity(msgUsefullData);
                    }
                        break;
                    case common::commonTypes::eMSG_PATTERN::MAKE_ASSOCIATION: {
                        msgUsefullData =
                                msgValidator_.getMessageInfo(common::commonTypes::eMSG_PATTERN::MAKE_ASSOCIATION,
                                                            userMessage);
                        controller_.makeEnttityAssociation(msgUsefullData);
                    }
                        break;
                    case common::commonTypes::eMSG_PATTERN::VIEW_ENTITY_INFO: {
                        msgUsefullData =
                                msgValidator_.getMessageInfo(common::commonTypes::eMSG_PATTERN::VIEW_ENTITY_INFO,
                                                            userMessage);
                        controller_.viewEntityData(msgUsefullData);
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

void cView::viewEntityInfo(const std::vector<std::pair<std::string, std::string>> &_entityDataToShow) {
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
//    if ( !_entityName.empty()) {
        std::cout << "Mentiont entity \"" << _entityName << "\" doesn't exists !" << std::endl;
//    } else {
//        logger_.printError(__FUNCTION__, "Data to show is empty");
//    }
}

void cView::errorEntityAlreadyExists(const std::string &_entityName) {
//    if ( !_entityName.empty()) {
        std::cout << "Mentiont entity short-name \"" << _entityName << "\" already exists!" << std::endl;
//    } else {
//        logger_.printError(__FUNCTION__, "Data to show is empty");
//    }
}

void cView::viewEntities(const std::vector<std::pair<std::string, std::string>> &_entityNames) {
//    if (!_entityNames.empty()) {
        std::cout << "Exists entities: " << std::endl;
        for (const auto names : _entityNames) {
            std::cout << names.first << " = " << names.second << std::endl;
        }
//    } else {
//        std::cout << "No data to show" << std::endl;
//    }
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

void cView::errorLoadData() {
    std::cout << "Storage error. Storage didn't load data!" << std::endl;
}

void cView::errorSaveData() {
    std::cout << "Storage error. Storage didn't save data! Is force save needed?" << std::endl;
}

void cView::errorDiagGenerationFailed() {
    std::cout << "Diag generation is failed." << std::endl;
}

