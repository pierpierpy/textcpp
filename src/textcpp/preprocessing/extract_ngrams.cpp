#include <sstream>      
#include <vector>       
#include <string>       
#include <algorithm>    
#include <cctype>       

std::vector<std::string> simple_tokenize(const std::string& text);

std::unordered_map<std::string, int> extract_ngrams(const std::string& text, int n) {
    std::vector<std::string> tokens = simple_tokenize(text);  // Define your tokenizer
    std::unordered_map<std::string, int> ngram_counts;

    for (size_t i = 0; i + n <= tokens.size(); ++i) {
        std::string ngram = tokens[i];
        for (int j = 1; j < n; ++j) {
            ngram += " " + tokens[i + j];
        }
        ngram_counts[ngram]++;
    }
    return ngram_counts;
}

std::vector<std::string> simple_tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::istringstream stream(text);
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
