#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <unordered_set>
#include <algorithm>
#include <cctype>

class Tokenizer {
public:
    virtual ~Tokenizer() = default;
    virtual std::vector<std::string> tokenize(const std::string& text) const = 0;
};


// ===== Simple Tokenizer =====
class SimpleTokenizer : public Tokenizer {
protected:
    std::unordered_set<std::string> stopwords;

public:
    SimpleTokenizer() = default;

    SimpleTokenizer(const std::unordered_set<std::string>& sw)
        : stopwords(sw) {}

    std::vector<std::string> tokenize(const std::string& text) const override {
        std::vector<std::string> tokens;
        std::istringstream stream(text);
        std::string token;

        while (stream >> token) {
            if (stopwords.empty() || stopwords.find(token) == stopwords.end()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }
};


// ===== Regex Tokenizer =====
class RegexTokenizer : public Tokenizer {
protected:
    std::regex pattern;
    std::unordered_set<std::string> stopwords;

public:
    RegexTokenizer(const std::string& regex_pattern = R"(\b\w+\b)")
        : pattern(regex_pattern) {}

    RegexTokenizer(const std::string& regex_pattern,
                   const std::unordered_set<std::string>& sw)
        : pattern(regex_pattern), stopwords(sw) {}

    std::vector<std::string> tokenize(const std::string& text) const override {
        std::vector<std::string> tokens;
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
        auto words_end = std::sregex_iterator();

        for (auto it = words_begin; it != words_end; ++it) {
            std::string token = it->str();
            if (stopwords.empty() || stopwords.find(token) == stopwords.end()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }
};

#endif  // TOKENIZER_H
