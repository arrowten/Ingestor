#include "logger.hpp"
#include <iostream>

// Print info log to console
void Logger::info(const std::string& message) {
    std::cout << "[INFO]: " << message << std::endl;
}