#include "stopword_utils.h"

std::vector<std::string> remove_stopwords(
    const std::vector<std::string>& tokens,
    const std::unordered_set<std::string>& stopwords)
{
    std::vector<std::string> filtered;
    for (const auto& token : tokens) {
        if (stopwords.find(token) == stopwords.end()) {
            filtered.push_back(token);
        }
    }
    return filtered;
}