//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_CONSTANTS_H
#define ASSOCIATIONMANAGER_CONSTANTS_H

#include <string>

namespace common {
namespace constants {

    static const bool kIsLoggerNeeded = true;

    static const std::string kCreateEntity = " = ";
    static const std::string kCreateAssociation = " - ";
    static const std::string kViewInfo = " ?";
    static const std::string kFileName = "AssociationManagerStorage.txt";
    static const uint VIEW_ENTITY_MAX_PARAMS_COUNT = 1;
    static const uint CREATE_ENTITY_MAX_PARAMS_COUNT = 2;
    static const uint MAKE_ASSOCIATION_MAX_PARAMS_COUNT = 3;

} // constants
} // common


#endif //ASSOCIATIONMANAGER_CONSTANTS_H
