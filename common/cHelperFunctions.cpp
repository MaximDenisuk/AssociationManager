//
// Created by mdenysiuk on 07.04.19.
//

#include "cHelperFunctions.h"

std::vector<std::string> cHelperFunctions::associationMnagerParser(const std::string &_msg) {
    Logger logger;
    std::vector<std::string> result;
    std::string keyWord = "",
                tmpMsg = _msg;
    unsigned int shiftFromLeft = 0;
    unsigned int endKeywordPosition = 0;

    while (shiftFromLeft != _msg.length()) {
        endKeywordPosition = tmpMsg.find(constants::kCreateAssociation);
        if (-1 != endKeywordPosition) {
            keyWord = tmpMsg.substr(0, endKeywordPosition);
            shiftFromLeft += endKeywordPosition + constants::kCreateAssociation.length();
            tmpMsg = _msg.substr(shiftFromLeft, _msg.length());

            if (!keyWord.empty()) {
                result.push_back(keyWord);
            } else {
                logger.printError(__FUNCTION__, "KeyWord is empty!");
                break;
            }
        } else if (shiftFromLeft < _msg.length()) {
            keyWord = tmpMsg.substr(0, _msg.length());
            if (!keyWord.empty()) {
                result.push_back(keyWord);
                shiftFromLeft = _msg.length();
            } else {
                logger.printError(__FUNCTION__, "KeyWord is empty!");
                break;
            }
        }
    }
    return result;
}