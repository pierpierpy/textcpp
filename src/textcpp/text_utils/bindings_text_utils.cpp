#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "operations.h"
#include "read.h"

namespace py = pybind11;

PYBIND11_MODULE(text_utils, m) {
    m.doc() = "Module with multiple C++ functions";
    m.def("count_words", &count_words, "count words in text file");
    m.def("frequency_count", &frequency_count, "make frequency word count from file");
    m.def("word_frequency_count", &word_frequency_count, "Counts how many times a word appears in a text file.");
    py::class_<Text>(m, "Text")
        .def(py::init<const std::string&>())  // Only file_path
        .def("read_text", &Text::get_content)
        .def("get_file_path", &Text::get_file_path);
}

