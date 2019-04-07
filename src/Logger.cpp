//
// Created by mdenysiuk on 03.04.19.
//

#include "Logger.h"

Logger::Logger(const bool _isLoggerNeeded): 
    isLoggerEnabled_(_isLoggerNeeded) {
}

void Logger::print(const std::string &_msgToPrint) {
    if (isLoggerEnabled_) {
        std::cout << _msgToPrint << std::endl;
    }
}

void Logger::print(const std::string &_functionName, const std::string &_msgToPrint) {
    if (isLoggerEnabled_) {
        std::cout << _functionName << separator_ << _msgToPrint << std::endl;
    }
}

void Logger::print(const std::string &_functionName, const std::string &_msgToPrint, const std::string &_param1) {
    if (isLoggerEnabled_) {
        std::cout << _functionName << separator_ << _msgToPrint << _param1 << std::endl;
    }
}

void Logger::print(const std::string &_functionName, const std::string &_msgToPrint, const std::string &_param1, const std::string &_param2) {
    if (isLoggerEnabled_) {
        std::cout << _functionName << separator_ << _msgToPrint << _param1 << _param2 << std::endl;
    }
}

void Logger::print(const std::string &_functionName, const std::string &_msgToPrint, const int &_param1) {
    if (isLoggerEnabled_) {
        std::cout << _functionName << separator_ << _msgToPrint << _param1 << std::endl;
    }
}

void Logger::print(const std::string &_functionName, const std::vector<std::string> &_param1) {
    if (isLoggerEnabled_) {
        std::cout << _functionName << separator_ << std::endl;
        for (const auto str : _param1) {
            std::cout << "\t" << separator_<< str << std::endl;
        }
    }
}

void Logger::printError(const std::string &_functionName, const std::string &_msgToPrint) {
    if (isLoggerEnabled_) {
        std::cout << std::endl << error_ << _functionName << separator_ << _msgToPrint << std::endl;
    }
}