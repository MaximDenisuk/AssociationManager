//
// Created by mdenysiuk on 04.04.19.
//

#include "cStorage.h"

//cStorage::cStorage(Logger _logger, cEntityController &_entityController):
//    logger_(_logger),
//    entityController_(_entityController) {
//    logger_.print("cStorage ctor");
//}

cStorage::cStorage(Logger &_logger):
        logger_(_logger) {
    logger_.print("cStorage ctor");
}

commonTypes::eSTATUS cStorage::saveData(std::vector<cEntity> _entitiesToSave) {
    logger_.print(__FUNCTION__);
    // TODO: release save logic with json/xml/yaml file structure
}

commonTypes::eSTATUS cStorage::saveData(const cEntity &_entitiesToSave) {
    logger_.print(__FUNCTION__);
    // TODO: release save logic with json/xml/yaml file structure
}


commonTypes::eSTATUS cStorage::requestLoadFullData() {
    logger_.print(__FUNCTION__);
    std::vector<cEntity> entitiesFromFile;

    // TODO: release load logic with json/xml/yaml file structure
    // TODO: update storedEntities_ when ready and send response

    storedEntities_ = entitiesFromFile;
//    responseLoadFullData();
}

