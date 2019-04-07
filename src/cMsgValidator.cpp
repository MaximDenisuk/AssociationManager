//
// Created by mdenysiuk on 03.04.19.
//

#include "cMsgValidator.h"

cMsgValidator::cMsgValidator(Logger &_logger):
    logger_(_logger) {
    logger_.print("cMsgValidator ctor");
}

commonTypes::eMSG_PATTERN cMsgValidator::isOneOfMsgPatterns(const std::string &_inputMsg) {
    return getRawMsgType(_inputMsg);
}

commonTypes::eMSG_PATTERN cMsgValidator::getRawMsgType(const std::string &_inputMsg) {
    logger_.print(__FUNCTION__);
    commonTypes::eMSG_PATTERN result = commonTypes::eMSG_PATTERN::UNKNOWN;
    if(-1 != _inputMsg.find(constants::kCreateEntity)) {
        logger_.print(__FUNCTION__ , "kCreateEntity");
        result = commonTypes::eMSG_PATTERN::CREATE_ENTITY;
    } else if(-1 != _inputMsg.find(constants::kCreateAssociation)) {
        logger_.print(__FUNCTION__, "kCreateAssociation");
        result = commonTypes::eMSG_PATTERN::MAKE_ASSOCIATION;
    } else if(-1 != _inputMsg.find(constants::kViewInfo)) {
        logger_.print(__FUNCTION__, "kViewInfo");
        result = commonTypes::eMSG_PATTERN::VIEW_ENTITY_INFO;
    }
    return result;
}

std::vector<std::string>
cMsgValidator::getMessageInfo(const commonTypes::eMSG_PATTERN &_msgType, std::string &_inputMessage) {
    logger_.print(__FUNCTION__);
    std::vector<std::string> result;
    switch (_msgType) {
        case commonTypes::eMSG_PATTERN::CREATE_ENTITY: {
            result = parseCreateMsg(_inputMessage);
        }
            break;
        case commonTypes::eMSG_PATTERN::MAKE_ASSOCIATION: {
            result = parseAssociationMsg(_inputMessage);
        }
            break;
        case commonTypes::eMSG_PATTERN::VIEW_ENTITY_INFO: {
            result = parseViewMsg(_inputMessage);
        }
            break;
        default: {
            logger_.printError(__FUNCTION__, "Wrong msg type received!!!");
        }
    }
    return result;
}


// a = Alex
// TODO: add handling of "a =  "
std::vector<std::string> cMsgValidator::parseCreateMsg (const std::string &_msg) {
    logger_.print(__FUNCTION__);
    const std::string __FUNCTION = __FUNCTION__;

    std::vector<std::string> result;
    if (!_msg.empty()) {
        auto push_back = [=](const std::string &_keyWord, std::vector<std::string> &_result) {
            if (_keyWord.empty()) {
                logger_.printError(__FUNCTION, "Wrong msg size received, msg is empty");
            } else {
                _result.push_back(_keyWord);
            }
        };
        const uint kFoundPos = _msg.find(constants::kCreateEntity);
        if (-1 != kFoundPos) {
            std::string keyWord = _msg.substr(0, kFoundPos);
            push_back(keyWord, result);

            const uint shiftFromLeft = kFoundPos + constants::kCreateEntity.length();
            keyWord = _msg.substr(shiftFromLeft, _msg.length());

            push_back(keyWord, result);
        } else {
            logger_.printError(__FUNCTION, "Separator not found!");
        }
    }

    logger_.print(__FUNCTION, "KeyWord 0 : ", result[0]);
    logger_.print(__FUNCTION, "KeyWord 0 : ", result[1]);
    return result;
}

std::vector<std::string> cMsgValidator::parseAssociationMsg (const std::string &_msg) {
    logger_.print(__FUNCTION__);
    std::vector<std::string> result;
    if (!_msg.empty()) {
        std::string keyWord = "",
                    tmpMsg = _msg;
        uint shiftFromLeft = 0;
        uint endKeywordPosition = 0;

        while (shiftFromLeft != _msg.length()) {
            endKeywordPosition = tmpMsg.find(constants::kCreateAssociation);
            if (-1 != endKeywordPosition) {
                keyWord = tmpMsg.substr(0, endKeywordPosition);
                shiftFromLeft += endKeywordPosition + constants::kCreateAssociation.length();
                tmpMsg = _msg.substr(shiftFromLeft, _msg.length());

                if (!keyWord.empty()) {
                    result.push_back(keyWord);
                } else {
                    logger_.printError(__FUNCTION__, "KeyWord is empty!");
                    break;
                }
            } else if (shiftFromLeft < _msg.length()) {
                keyWord = tmpMsg.substr(0, _msg.length());
                if (!keyWord.empty()) {
                    result.push_back(keyWord);
                    shiftFromLeft = _msg.length();
                } else {
                    logger_.printError(__FUNCTION__, "KeyWord is empty!");
                    break;
                }
            }
        }
    } else {
        logger_.printError(__FUNCTION__, "Input msg is empty");
    }

    logger_.print(__FUNCTION__, result);
    return result;
}

std::vector<std::string> cMsgValidator::parseViewMsg (const std::string &_msg) {
    logger_.print(__FUNCTION__);
    std::vector<std::string> result;

    if (!_msg.empty()) {
        const uint kFoundPos = _msg.find(constants::kViewInfo);
        if (-1 != kFoundPos) {
            std::string keyWord = _msg.substr(0, kFoundPos);
            if (!keyWord.empty()) {
                result.push_back(keyWord);
            } else {
                logger_.printError(__FUNCTION__, "Wrong msg size received, msg is empty");
            }
        } else {
            logger_.printError(__FUNCTION__, "Separator not found!");
        }
    }
    logger_.print(__FUNCTION__, "KeyWord: ", result[0]);
    return result;
}