#include "transformer.hpp"
#include <algorithm>

// Transform input string to uppercase
std::string Transformer::transform(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    
    return result;
}