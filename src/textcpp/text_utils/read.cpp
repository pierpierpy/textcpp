#include "read.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Constructor that initializes with a file path
Text::Text(const std::string& file_path) 
    : file_path(file_path), is_loaded(false) {}

// Function to read the content of a file and return it as a string
std::string Text::read_text(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + file_path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Getter for the content (only loads it once)
const std::string& Text::get_content() {
    if (!is_loaded) {
        content = read_text(file_path);  // Load content from file if not already loaded
        is_loaded = true;                // Mark the content as loaded
    }
    return content;  // Return the loaded content
}

// Getter for file path
const std::string& Text::get_file_path() const {
    return file_path;
}

// ChunkReader constructor and methods
// (This is already declared in the header)
