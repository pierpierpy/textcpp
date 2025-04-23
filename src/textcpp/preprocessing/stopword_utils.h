#ifndef STOPWORD_UTILS_H
#define STOPWORD_UTILS_H

#include <unordered_set>
#include <vector>
#include <string>

std::vector<std::string> remove_stopwords(
    const std::vector<std::string>& tokens,
    const std::unordered_set<std::string>& stopwords);

#endif