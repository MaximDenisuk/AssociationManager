//
// Created by mdenysiuk on 04.04.19.
//

#include <fstream>
#include "cStorage.h"
#include "cHelperFunctions.h"

cStorage::cStorage(Logger _logger, cEntityController &_entityController):
    logger_(_logger),
    entityController_(_entityController) {
    logger_.print("cStorage ctor");
}

commonTypes::eSTATUS cStorage::requestSaveFullData(std::vector<cEntity> _entitiesToSave) {
    logger_.print(__FUNCTION__);
    if (!_entitiesToSave.empty()) {
        std::ofstream file;
        file.open (constants::kFileName);

        for (const auto entity: _entitiesToSave) {
            file <<  "- Entity:\n";
            file << "short_name:" << entity.getShortName_() << "\n";
            file << "long_name:" << entity.getLongName_() << "\n";
            for (const auto association : entity.getAssociationList()) {
                file << "associations:"
                     << entity.getShortName_()
                     << " - " << association.first
                     << " - "
                     << association.second
                     << "\n";
            }
        }
        file.close();
    } else {
        logger_.print(__FUNCTION__, "Nothing to write. Storage is empty.");
    }
}

commonTypes::eSTATUS cStorage::requestSaveData(const cEntity &_entitiesToSave) {
    logger_.print(__FUNCTION__);
    // TODO: release partial save logic with json/xml/yaml file structure
}

commonTypes::eSTATUS cStorage::requestLoadFullData() {
    logger_.print(__FUNCTION__);

    std::ifstream myfile (constants::kFileName);
    const std::string kEntityStart = "- Entity:";
    const std::string kAssociations = "association:";
    const std::string kShortName = "short_name:";
    const std::string kLongName = "long_name:";
    std::vector<cEntity> entitiesFromFile;
    std::string linefromFile;

    if (myfile.is_open()) {
        cEntity entity("", "");
        while (getline(myfile, linefromFile)) {
            if (0 == linefromFile.compare(kEntityStart) &&
                !entity.getShortName_().empty() &&
                !entity.getLongName_().empty()) {
                entitiesFromFile.push_back(entity);
                logger_.print(__FUNCTION__, "push entity: ", entity.getLongName_());
            } else if (const auto namePos = linefromFile.find(kShortName) != std::string::npos) {
                entity.setShortName_(linefromFile.substr(namePos + kShortName.length(), linefromFile.length()));
            } else if (const auto namePos = linefromFile.find(kLongName) != std::string::npos) {
                entity.setLongName_(linefromFile.substr(namePos + kLongName.length(), linefromFile.length()));
            } else if (const auto namePos = linefromFile.find(kAssociations) != std::string::npos) {
                std::string associationLine = linefromFile.substr(namePos + kAssociations.length(), linefromFile.length());
                if (!associationLine.empty()) {
                    std::vector<std::string> associationData =
                            cHelperFunctions::associationMnagerParser(associationLine);
                    if (!associationData.empty() &&
                        constants::MAKE_ASSOCIATION_MAX_PARAMS_COUNT == associationData.size()) {
                        if (!associationData[1].empty() && !associationData[2].empty()) {
                            entity.addAssociation(associationData[2], associationData[1]);
                        } else {
                            logger_.printError(__FUNCTION__, "read names are incorrect!");
                        }

                    } else {
                        logger_.printError(__FUNCTION__, "Wrong association parameters size!");
                    }
                } else {
                    logger_.printError(__FUNCTION__, "Association line is empty!");
                }
            } else {
                logger_.printError(__FUNCTION__, "Unhandled line!!! Smth go wrong");
            }
        }
        myfile.close();
    } else {
        logger_.printError(__FUNCTION__, "File is already opened");
    }
    storedEntities_ = entitiesFromFile;
    responseLoadFullData();
}

void
cStorage::responseLoadFullData() {
    logger_.print(__FUNCTION__);
    entityController_.responseLoadFullData();
}