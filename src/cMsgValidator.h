//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_CMSGVALIDATOR_H
#define ASSOCIATIONMANAGER_CMSGVALIDATOR_H

#include <string>
#include <vector>
#include "common/commonTypes.h"
#include "common/constants.h"
#include "common/Logger.h"

namespace constants = common::constants;
namespace commonTypes = common::commonTypes;

class cMsgValidator {
private:
    commonTypes::eMSG_PATTERN getRawMsgType(const std::string &_inputMsg);
    std::vector<std::string> parseCreateMsg (const std::string &_msg);
    std::vector<std::string> parseAssociationMsg (const std::string &_msg);
    std::vector<std::string> parseViewMsg (const std::string &_msg);

    Logger &logger_;
public:
    commonTypes::eMSG_PATTERN isOneOfMsgPatterns(const std::string &_inputMsg);
    std::vector<std::string> getMessageInfo(const commonTypes::eMSG_PATTERN &_msgType, std::string &_inputMessage);

    cMsgValidator(Logger &_logger);
};


#endif //ASSOCIATIONMANAGER_CMSGVALIDATOR_H
