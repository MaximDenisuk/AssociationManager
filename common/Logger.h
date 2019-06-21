//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_LOGGER_H
#define ASSOCIATIONMANAGER_LOGGER_H


#include <string>
#include <iostream>
#include <vector>
#include "constants.h"

class Logger {
public:
    void print(const std::string _msgToPrint);
    void print(const std::string _functionName, const std::string _msgToPrint);
    void print(const std::string _functionName, const std::string _msgToPrint, const std::string _param1);
    void print(const std::string _functionName, const std::string _msgToPrint, const std::string _param1, const std::string _param2);
    void print(const std::string _functionName, const std::string _msgToPrint, const int _param1);
    void print(const std::string _functionName, const std::vector<std::string> _param1);

    void printError(const std::string _functionName, const std::string _msgToPrint);
    void printError(const std::string _functionName, const std::string _msgToPrint, const std::string _param1);
};

#endif //ASSOCIATIONMANAGER_LOGGER_H
