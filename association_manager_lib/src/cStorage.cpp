//
// Created by mdenysiuk on 04.04.19.
//

#include <fstream>
#include "cStorage.h"
#include "../../common/cHelperFunctions.h"
#include "../cEntityController.h"

const std::string ENTITY_START = "- Entity:";
const std::string ASSOCIATION_START = "association: ";
const std::string SHORT_NAME = "short_name:";
const std::string LONG_NAME = "long_name:";

cStorage::cStorage(Logger _logger, cEntityController &_entityController):
    logger_(_logger),
    entityController_(_entityController) {
    logger_.print("cStorage ctor");
}

commonTypes::eSTATUS cStorage::requestSaveFullData(std::vector<cEntity> _entitiesToSave) {
    logger_.print(__FUNCTION__);
    currentStatus_ = commonTypes::eSTATUS::IN_PROGRESS;
    if (!_entitiesToSave.empty()) {
        std::ofstream file;
        file.open (constants::kFileName);

        for (const auto entity: _entitiesToSave) {
            file <<  ENTITY_START << "\n";
            file << SHORT_NAME << entity.getShortName_() << "\n";
            file << LONG_NAME << entity.getLongName_() << "\n";
            for (const auto association : entity.getAssociationList()) {
                file << ASSOCIATION_START
                     << entity.getShortName_()
                     << " - " << association.first
                     << " - "
                     << association.second
                     << "\n";
            }
        }
        file.close();
        currentStatus_ = commonTypes::eSTATUS::COMPLETE;
    } else {
        logger_.print(__FUNCTION__, "Nothing to write. Storage is empty.");
        currentStatus_ =  commonTypes::eSTATUS::ERROR;
    }
    return currentStatus_;
}

commonTypes::eSTATUS cStorage::requestSaveData(const cEntity &_entitiesToSave) {
    logger_.print(__FUNCTION__);
    // TODO: release partial save logic with json/xml/yaml file structure
    return commonTypes::eSTATUS::COMPLETE;
}

commonTypes::eSTATUS cStorage::requestLoadFullData() {
    logger_.print(__FUNCTION__);
    currentStatus_ =  commonTypes::eSTATUS::IN_PROGRESS;;
    std::ifstream myfile (constants::kFileName);
    std::string linefromFile = "";
    std::vector<cEntity> readEntities;
    if (myfile.is_open()) {
        cEntity entity("", "");

        const auto pushIfPossible = [&] (const cEntity &_entity) {
            if (!_entity.getShortName_().empty() &&
                !_entity.getLongName_().empty()) {
                readEntities.push_back(entity);
                logger_.print("requestLoadFullData", "push entity: ", entity.getLongName_());
                entity = cEntity("", "");
            }
        };

        while (getline(myfile, linefromFile)) {
            if (0 == linefromFile.compare(ENTITY_START)) {
                pushIfPossible(entity);
            } else if (linefromFile.find(SHORT_NAME) != -1) {
                std::string tmpStr = linefromFile.substr(SHORT_NAME.length(), linefromFile.length());
                entity.setShortName_(tmpStr);
            } else if (linefromFile.find(LONG_NAME) != -1) {
                std::string tmpStr = linefromFile.substr(LONG_NAME.length(), linefromFile.length());
                entity.setLongName_(tmpStr);
            } else if (linefromFile.find(ASSOCIATION_START) != -1) {
                std::string associationLine = linefromFile.substr(ASSOCIATION_START.length(), linefromFile.length());
                if (!associationLine.empty()) {
                    std::vector<std::string> associationData =
                            cHelperFunctions::associationMnagerParser(associationLine);
                    if (!associationData.empty() &&
                        constants::MAKE_ASSOCIATION_MAX_PARAMS_COUNT == associationData.size()) {
                        if (!associationData[1].empty() && !associationData[2].empty()) {
                            entity.addAssociation(associationData[1], associationData[2]);
                        } else {
                            logger_.print(__FUNCTION__, "read names are incorrect!");
                            break;
                        }
                    } else {
                        logger_.print(__FUNCTION__, "Wrong association parameters size!");
                        break;
                    }
                } else {
                    logger_.print(__FUNCTION__, "Association line is empty!");
                    break;
                }
            }
        }
        if (0 == linefromFile.compare("")) {
            pushIfPossible(entity);
        }
        myfile.close();
        currentStatus_ = commonTypes::eSTATUS::COMPLETE;
    } else {
        logger_.print(__FUNCTION__, "File is already opened");
        currentStatus_ =  commonTypes::eSTATUS::ERROR;
    }
    storedEntities_ = readEntities;
    responseLoadFullData();
    return currentStatus_;
}

void cStorage::responseLoadFullData() {
    logger_.print(__FUNCTION__);
    entityController_.responseLoadFullData();
}


commonTypes::eSTATUS cStorage::generateUseCaseDiagr(std::vector<cEntity> _entitiesToSave) {
    logger_.print(__FUNCTION__);
    if (!_entitiesToSave.empty()) {
        std::ofstream file;
        file.open (constants::kDiagName);
        std::vector<std::string> aliases;
        std::vector<std::string> associations;

        for (const auto entity: _entitiesToSave) {
            aliases.push_back(entity.getLongName_() + " as " + entity.getShortName_() + "\n");
            for (const auto association : entity.getAssociationList()) {
                std::string formedAssociation =
                   "(" + entity.getShortName_() + ") --> (" + association.second + ")" + ": " + association.first + "\n";
                associations.push_back(formedAssociation);
            }
        }

        file << "@startuml\n" << "left to right direction" << "\n\n";
        for (const auto alias : aliases) {
            file << alias;
        }

        file << "\n";

        for (const auto association : associations) {
            file << association;
        }

        file <<"\n@enduml";
        file.close();
    } else {
        logger_.print(__FUNCTION__, "Nothing to write. Storage is empty.");
    }
    return commonTypes::eSTATUS::COMPLETE;
}

commonTypes::eSTATUS cStorage::generateObjectDiagr(std::vector<cEntity> _entitiesToSave) {
    logger_.print(__FUNCTION__);
    
    if (!_entitiesToSave.empty()) {
        std::ofstream file;
        file.open (constants::kDiagName);
        std::vector<std::string> aliases;
        std::vector<std::string> associations;

        for (const auto entity: _entitiesToSave) {
            aliases.push_back("object \"" + entity.getLongName_() + "\" as " + entity.getShortName_() + "\n");
            for (const auto association : entity.getAssociationList()) {
                std::string formedAssociation =
                        entity.getShortName_() + " --|> " + association.second + ": " + association.first + "\n";
                associations.push_back(formedAssociation);
            }
        }

        file << "@startuml\n" << "left to right direction" << "\n\n";
        for (const auto alias : aliases) {
            file << alias;
        }

        file << "\n";

        for (const auto association : associations) {
            file << association;
        }

        file <<"\n@enduml";
        file.close();
    } else {
        logger_.print(__FUNCTION__, "Nothing to write. Storage is empty.");
    }
    return commonTypes::eSTATUS::COMPLETE;
}