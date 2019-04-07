//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_CENTITYCONTROLLER_H
#define ASSOCIATIONMANAGER_CENTITYCONTROLLER_H


#include <string>
#include <vector>
#include "Logger.h"
#include "../common/constants.h"
#include "cStorage.h"
#include "cEntity.h"
//#include "cView.h"

namespace constants = common::constants;

class cEntityController {
private:
    Logger &logger_;
//    cView &viewer_;
    cStorage storage_;
    std::vector<cEntity> entitiesList_;

    void tmpViewEntityInfo(const std::vector<std::pair<std::string, std::string>> &_entityDataToShow);

public:
    void responseLoadFullData();
    void createEntity(const std::vector<std::string> &_msgData);
    void makeEnttityAssociation(const std::vector<std::string> &_msgData);
    void viewEntityData(const std::vector<std::string> &_msgData);

//    cEntityController(Logger &_logger, cView &_viewer));
    cEntityController(Logger &_logger);
};

inline void
cEntityController::responseLoadFullData() {
    entitiesList_ = storage_.getStoredEntities_();
}

#endif //ASSOCIATIONMANAGER_CENTITYCONTROLLER_H
