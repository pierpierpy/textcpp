#ifndef READ_H
#define READ_H

#include <string>
#include <iterator>
#include <fstream>
#include <memory>

class Text {
private:
    std::string content;   // To store file content (for lazy loading)
    std::string file_path; // To store the path of the file
    bool is_loaded;        // To track whether content is loaded or not

    // Private method to load the full content (for lazy loading)
    std::string read_text(const std::string& file_path);

public:
    // Constructor that initializes the file path
    Text(const std::string& file_path);

    // Getter for the content (loads text only when needed)
    const std::string& get_content();

    // Getter for file path
    const std::string& get_file_path() const;

    // Function that returns an iterator-like object for chunk reading
    class ChunkReader {
    private:
        std::ifstream file;
        std::string buffer;
        std::size_t chunk_size;

    public:
        ChunkReader(const std::string& file_path, std::size_t chunk_size)
            : file(file_path, std::ios::binary), chunk_size(chunk_size) {
            if (!file.is_open()) {
                throw std::runtime_error("Error opening file: " + file_path);
            }
        }

        // Iterator function that yields chunks of file content
        bool read_next_chunk() {
            buffer.clear();
            char temp[chunk_size];
            file.read(temp, chunk_size);
            std::streamsize bytes_read = file.gcount();
            if (bytes_read > 0) {
                buffer.append(temp, bytes_read);
            }
            return bytes_read > 0;  // Return true if there is more content
        }

        const std::string& get_chunk() const {
            return buffer;
        }
    };

    // Method to create a ChunkReader object
    ChunkReader get_chunk_reader(std::size_t chunk_size) {
        return ChunkReader(file_path, chunk_size);
    }
};

#endif // READ_H
