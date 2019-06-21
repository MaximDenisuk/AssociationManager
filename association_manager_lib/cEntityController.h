//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_CENTITYCONTROLLER_H
#define ASSOCIATIONMANAGER_CENTITYCONTROLLER_H

#include <string>
#include <vector>
#include "common/Logger.h"
#include "common/constants.h"
#include "src/cStorage.h"
#include "src/cEntity.h"

namespace constants = common::constants;

class cEntityController {
private:
    Logger &logger_;
    cStorage storage_;
    std::vector<cEntity> entitiesList_;

public:
    void responseLoadFullData();
    commonTypes::eAMErrorTypes createEntity(const std::vector<std::string> &_msgData);
    commonTypes::eAMErrorTypes makeEnttityAssociation(const std::vector<std::string> &_msgData);
    std::pair<commonTypes::eAMErrorTypes, std::vector<std::pair<std::string, std::string>>> viewEntityData(const std::vector<std::string> &_msgData);
    std::pair<commonTypes::eAMErrorTypes, std::vector<std::pair<std::string, std::string>>> viewEntities();
    commonTypes::eAMErrorTypes generateUseCaseDiagr();
    commonTypes::eAMErrorTypes generateObjDiagr();

    cEntityController(Logger &_logger);
};

#endif //ASSOCIATIONMANAGER_CENTITYCONTROLLER_H
