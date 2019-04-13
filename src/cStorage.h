//
// Created by mdenysiuk on 04.04.19.
//

#ifndef ASSOCIATIONMANAGER_CSTORAGE_H
#define ASSOCIATIONMANAGER_CSTORAGE_H


#include "../common/commonTypes.h"
#include "Logger.h"
#include "cEntity.h"
#include "../common/constants.h"

class cEntityController;

namespace commonTypes = common::commonTypes;
namespace constants = common::constants;

class cStorage {
private:
    // TODO: add msg qeue for data saving + setters
    // TODO: start msg qeue in separate thread

    void responseLoadFullData();

    Logger &logger_;
    cEntityController &entityController_;

    std::vector<cEntity> storedEntities_;
    // TODO: add status hadling after func calls
    commonTypes::eSTATUS currentStatus_;
public:
    commonTypes::eSTATUS requestSaveFullData(std::vector<cEntity> _entitiesToSave);
    commonTypes::eSTATUS requestSaveData(const cEntity &_entitiesToSave);
    commonTypes::eSTATUS requestLoadFullData();
    commonTypes::eSTATUS getCurrentStatus_() const;
    const std::vector<cEntity> &getStoredEntities_() const;
    commonTypes::eSTATUS generateUseCaseDiagr(std::vector<cEntity> _entitiesToSave);
    commonTypes::eSTATUS generateObjectDiagr(std::vector<cEntity> _entitiesToSave);

    cStorage(Logger _logger, cEntityController &_entityController);
};

inline const std::vector<cEntity> &
cStorage::getStoredEntities_() const {
    return storedEntities_;
}

inline commonTypes::eSTATUS
cStorage::getCurrentStatus_() const {
    return currentStatus_;
}

#endif //ASSOCIATIONMANAGER_CSTORAGE_H
