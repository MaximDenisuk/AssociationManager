//
// Created by mdenysiuk on 07.04.19.
//

#ifndef ASSOCIATIONMANAGER_CHELPERFUNCTIONS_H
#define ASSOCIATIONMANAGER_CHELPERFUNCTIONS_H


#include <string>
#include <vector>
#include "../common/constants.h"
#include "Logger.h"

namespace constants = common::constants;
class cHelperFunctions {
public:
    static std::vector<std::string> associationMnagerParser(const std::string &_msg);

    cHelperFunctions();
};


#endif //ASSOCIATIONMANAGER_CHELPERFUNCTIONS_H
