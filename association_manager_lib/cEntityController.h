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

class cView;

namespace constants = common::constants;

class cEntityController {
private:
    Logger &logger_;
    cView &viewer_;
    cStorage storage_;
    std::vector<cEntity> entitiesList_;

public:
    void responseLoadFullData();
    void createEntity(const std::vector<std::string> &_msgData);
    void makeEnttityAssociation(const std::vector<std::string> &_msgData);
    void viewEntityData(const std::vector<std::string> &_msgData);
    void viewEntities();
    void generateUseCaseDiagr();
    void generateObjDiagr();

    cEntityController(Logger &_logger, cView &_viewer);
};

#endif //ASSOCIATIONMANAGER_CENTITYCONTROLLER_H
