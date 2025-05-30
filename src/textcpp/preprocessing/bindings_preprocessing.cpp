#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "operations.h"  // Assuming your extract_ngrams declaration is here
#include "tokenizer.h"

namespace py = pybind11;

PYBIND11_MODULE(preprocessing, m) {
    m.doc() = "Preprocessing tools";

    py::class_<Tokenizer>(m, "Tokenizer")
        .def("tokenize", &Tokenizer::tokenize);

    py::class_<SimpleTokenizer, Tokenizer>(m, "SimpleTokenizer")
        .def(py::init<>())  // No stopwords
        .def(py::init<const std::unordered_set<std::string>&>())
        .def("tokenize", &SimpleTokenizer::tokenize);

    // RegexTokenizer binding with regex + optional stopwords
    py::class_<RegexTokenizer, Tokenizer>(m, "RegexTokenizer")
        .def(py::init<const std::string&>())  // Only regex
        .def(py::init<const std::string&, const std::unordered_set<std::string>&>())  // Regex + stopwords
        .def("tokenize", &RegexTokenizer::tokenize);


    // Use lambda for proper polymorphic binding
    m.def("extract_ngrams", 
        [](const std::string& input, int n, const Tokenizer& tokenizer, bool is_file,bool normalize) {
            return extract_ngrams(input, n, tokenizer, is_file,normalize);
        },
        py::arg("input"), 
        py::arg("n"), 
        py::arg("tokenizer"), 
        py::arg("is_file") = false,
        py::arg("normalize") = false,
        "Extract n-grams from text or file using a tokenizer"
    );
    m.def("remove_stopwords", &remove_stopwords,
        "Remove stopwords from token list");
    m.def("normalize_text", &normalize_text, "Normalize text (lowercase, remove punctuation, extra whitespace)");

}
