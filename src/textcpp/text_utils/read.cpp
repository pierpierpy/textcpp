#include <fstream>
#include <sstream>
#include <string>
#include "read.h"
std::string read_text(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + file_path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Read the whole file into the string stream

    return buffer.str(); // Return the entire content as a string
}