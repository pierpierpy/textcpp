#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "operations.h"
#include "read.h"

namespace py = pybind11;

PYBIND11_MODULE(text_utils, m) {
    m.doc() = "Module with multiple C++ functions";

    // Exposing the existing functions
    m.def("count_words", &count_words, "Count words in a text file");
    m.def("frequency_count", &frequency_count, "Generate frequency count of words from a file");
    m.def("word_frequency_count", &word_frequency_count, "Counts how many times a word appears in a text file.");

    // Exposing the Text class
    py::class_<Text>(m, "Text")
        .def(py::init<const std::string&>())  // Only file_path (file path as argument)
        .def("read_text", &Text::get_content, "Get the content of the file")
        .def("get_file_path", &Text::get_file_path, "Get the file path")
        
        .def("get_chunk_reader", &Text::get_chunk_reader, py::arg("chunk_size"),
            "Get a chunk reader to read the file in chunks of a specified size")
    ;

    py::class_<Text::ChunkReader>(m, "ChunkReader")
        .def("read_next_chunk", &Text::ChunkReader::read_next_chunk, "Read the next chunk")
        .def("get_chunk", &Text::ChunkReader::get_chunk, "Get the current chunk");
}
