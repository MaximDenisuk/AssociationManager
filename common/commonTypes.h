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



} // namespace constants
} // namespace common

#endif //ASSOCIATIONMANAGER_COMMONTYPES_H
