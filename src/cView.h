//
// Created by mdenysiuk on 06.04.19.
//

#ifndef ASSOCIATIONMANAGER_CVIEW_H
#define ASSOCIATIONMANAGER_CVIEW_H

#include "cMsgValidator.h"
#include "../association_manager_lib/cEntityController.h"

class cView {
private:
    Logger logger_;
    cMsgValidator msgValidator_;
    cEntityController controller_;
    bool isLoggerNeeded_;

    void startInput();
public:
    void start();

    void viewEntityInfo(const std::vector<std::pair<std::string, std::string> > &_entityDataToShow);
    void viewEntities(const std::vector<std::pair<std::string, std::string> > &_entityNames);
    void actionComplete();

    void errorEntityNotFound(const std::string &_entityName);
    void errorEntityAlreadyExists(const std::string &_entityName);
    void errorAssociationAlreadyExists(const std::pair<std::string, std::string> &_association);
    void errorCorruptedEntityNames();
    void errorLoadData();
    void errorSaveData();
    void errorDiagGenerationFailed();

    cView(const bool _isLoggerNeeded);
    ~cView();
};


#endif //ASSOCIATIONMANAGER_CVIEW_H
