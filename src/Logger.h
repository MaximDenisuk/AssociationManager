//
// Created by mdenysiuk on 03.04.19.
//

#ifndef ASSOCIATIONMANAGER_LOGGER_H
#define ASSOCIATIONMANAGER_LOGGER_H


#include <string>
#include <iostream>
#include <vector>

class Logger {
private:
    const bool isLoggerEnabled_;
    const std::string separator_ = ": ";
    const std::string error_ = "ERROR:\t";

public:

    // TODO: make template logger functions

    void print(const std::string &_msgToPrint);
    void print(const std::string &_functionName, const std::string &_msgToPrint);
    void print(const std::string &_functionName, const std::string &_msgToPrint, const std::string &_param1);
    void print(const std::string &_functionName, const std::string &_msgToPrint, const std::string &_param1, const std::string &_param2);
    void print(const std::string &_functionName, const std::string &_msgToPrint, const int &_param1);
    void print(const std::string &_functionName, const std::vector<std::string> &_param1);
    void printError(const std::string &_functionName, const std::string &_msgToPrint);

    Logger(const bool _isLoggerNeeded);
};

#endif //ASSOCIATIONMANAGER_LOGGER_H
