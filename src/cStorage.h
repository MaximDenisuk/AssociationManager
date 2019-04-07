//
// Created by mdenysiuk on 04.04.19.
//

#ifndef ASSOCIATIONMANAGER_CSTORAGE_H
#define ASSOCIATIONMANAGER_CSTORAGE_H


#include "../common/commonTypes.h"
#include "Logger.h"
#include "cEntity.h"
//#include "cEntityController.h"

namespace commonTypes = common::commonTypes;

class cStorage {
private:
    // TODO: add msg qeue for data saving + setters
    // TODO: start msg qeue in separate thread
//    void responseLoadFullData();

    Logger logger_;
    std::vector<cEntity> storedEntities_;
//    cEntityController& entityController_;

public:
    commonTypes::eSTATUS saveData(std::vector<cEntity> _entitiesToSave);
    commonTypes::eSTATUS requestLoadFullData();
    const std::vector<cEntity> &getStoredEntities_() const;

//    cStorage(Logger _logger, cEntityController &_entityController);
    cStorage(Logger &_logger);
};

inline const std::vector<cEntity> &
cStorage::getStoredEntities_() const {
    return storedEntities_;
}

//inline void
//cStorage::responseLoadFullData() {
//    logger_.print(__FUNCTION__);
//    entityController_.responseLoadFullData();
//}

#endif //ASSOCIATIONMANAGER_CSTORAGE_H
