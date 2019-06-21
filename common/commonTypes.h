//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_COMMONTYPES_H
#define ASSOCIATIONMANAGER_COMMONTYPES_H


namespace common {
namespace commonTypes {

    enum class eMSG_PATTERN {
        UNKNOWN = 0,
        CREATE_ENTITY,
        MAKE_ASSOCIATION,
        VIEW_ENTITY_INFO,
    };

    enum class eSTATUS {
        UNKNOWN = 0,
        COMPLETE,
        ERROR,
        IN_PROGRESS,
    };

    enum class eAMErrorTypes {
        ERROR_UNKNOWN = -1,
        NO_ERROR = 0,
        ERROR_SAVE_DATA,
        ERROR_ENTITY_ALREADY_EXISTS,
        ERROR_ENTITY_NOT_FOUND,
        ERROR_ASSOCIATION_ALREADY_EXISTS,
        ERROR_CORRUPTED_ENTITY_NAMES,
        ERROR_DIAG_GENERATION_FAILED,
    };



} // namespace constants
} // namespace common

#endif //ASSOCIATIONMANAGER_COMMONTYPES_H
