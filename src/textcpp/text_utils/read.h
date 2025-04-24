#ifndef READ_H
#define READ_H

#include <string>

class Text {
private:
    std::string content;   // To store file content
    std::string file_path; // To store the path of the file
    bool is_loaded;        // To track whether content is loaded or not

    // Private method to load the content from the file
    std::string read_text(const std::string& file_path);

public:
    // Constructor that initializes the file path
    Text(const std::string& file_path);

    // Getter for the content (loads text only when needed)
    const std::string& get_content();

    // Getter for file path
    const std::string& get_file_path() const;
};

#endif // READ_H



