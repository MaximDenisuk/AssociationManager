//
// Created by mdenysiuk on 06.04.19.
//

#ifndef ASSOCIATIONMANAGER_CVIEW_H
#define ASSOCIATIONMANAGER_CVIEW_H

#include "cMsgValidator.h"
#include "cEntityController.h"

class cView {
private:
    Logger logger_;
    cMsgValidator msgValidator_;
    cEntityController controller_;
    bool isLoggerNeeded_;

    void startInput();
public:
    void start();

    void viewEntityInfo(const std::vector<std::pair<std::string, std::string>> &_entityDataToShow);
    void entityNotFoundError(const std::string &_entityName);
    void entityAlreadyExists(const std::string &_entityName);

    cView(const bool _isLoggerNeeded);
    ~cView();
};


#endif //ASSOCIATIONMANAGER_CVIEW_H
