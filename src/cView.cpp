//
// Created by mdenysiuk on 06.04.19.
//

#include "cView.h"

cView::cView(const bool _isLoggerNeeded):
        logger_(Logger(_isLoggerNeeded)),
        msgValidator_(cMsgValidator(logger_)),
        controller_(cEntityController(logger_)) {

}


cView::~cView() {
//    logger_.print(__FUNCTION__);
//    delete[] (controller_);
//    delete[] (msgValidator_);
//    delete[] (logger_);
}

void cView::startInput() {
    auto help = [] {
        std::cout << "Hello, this is Association Manager!" << std::endl <<
                  "In this programm you are able to:" << std::endl <<
                  "1) create Entity using simple command \"=\", like:" << std::endl <<
                  "a = Alex " << std::endl <<
                  "2) make association between entities using \"- key -\", like:" << std::endl <<
                  "a - to do the best - a"<< std::endl <<
                  "3) print all data related to Entity using command \"?\", like:" << std::endl <<
                  "a ?" << std::endl <<
                  "For exit type \"q\"" << std::endl <<
                  // TODO: add Force save after atomic save realisation
                  //                  "If you want to make force save type \"forceSave\"" << std::endl <<
                  "TO see this msg again type \"help\"" << std::endl;
    };
    auto wrongSyntax = [] {
        std::cout << "Wrong syntax!" << std::endl;
    };

    help();

    std::string userMessage = "";
    while(true) {
        std::getline(std::cin, userMessage);
        std::cout << userMessage;
        if (!userMessage.empty()) {
            if (userMessage.compare("q") == 0) {
                break;
            } else if (userMessage.compare("help") == 0) {
                help();
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

//TODO: Find solution aout how to share cView to controller
//void cView::viewEntityInfo(const std::vector<std::pair<std::string, std::string>> &_entityDataToShow) {
//    //    std::cout << "\t:" << association.first << " . " << association.second << std::endl;
//    if (!_entityDataToShow.empty()) {
//        std::string entityName;
//        if (!_entityDataToShow[0].second.empty()) {
//            entityName = _entityDataToShow[0].second;
//        } else if (!_entityDataToShow[0].first.empty()) {
//            entityName = _entityDataToShow[0].first;
//        }
//        std::cout << "Entity name is: " << entityName << std::endl;
//        std::cout << "Assotiacions list: " << std::endl;
////        for (std::iterator it = _entityDataToShow.begin()+1;; )
//        for(std::vector<std::pair<std::string, std::string>>::const_iterator itAssotioation = _entityDataToShow.begin()+1;
//            itAssotioation != _entityDataToShow.end();
//            ++itAssotioation) {
//            if (!itAssotioation.first.empty() && !itAssotioation.second.empty()) {
//                std::cout << "\t: " << itAssotioation.first << " -. " << itAssotioation.second << std::endl;
//            }
//        }
//
//    } else {
//
//        logger_.printError(__FUNCTION__, "Data to show is empty");
//    }
//}