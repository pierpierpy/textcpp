#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "operations.h"  // Assuming your extract_ngrams declaration is here
#include <sstream>

namespace py = pybind11;

// Forward declare SimpleTokenizer if needed
class SimpleTokenizer {
    public:
        std::vector<std::string> tokenize(const std::string& text) const {
            std::vector<std::string> tokens;
            std::istringstream stream(text);
            std::string token;
            while (stream >> token) {
                tokens.push_back(token);
            }
            return tokens;
        }
    };
    
PYBIND11_MODULE(preprocessing, m) {
    m.doc() = "Preprocessing";

    py::class_<SimpleTokenizer>(m, "SimpleTokenizer")
        .def(py::init<>())
        .def("tokenize", &SimpleTokenizer::tokenize);

    m.def("extract_ngrams", 
        &extract_ngrams, 
        py::arg("input"), 
        py::arg("n"), 
        py::arg("tokenizer"), 
        py::arg("is_file") = false,
        "Extract n-grams from text or file using a tokenizer"
    );
}
