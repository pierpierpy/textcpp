#include <string>
#include <algorithm>
#include <cctype>
#include <regex>

std::string normalize_text(const std::string& text) {
    std::string normalized_text = text;
    
    // Convert to lowercase
    std::transform(normalized_text.begin(), normalized_text.end(), normalized_text.begin(), ::tolower);
    
    // Remove punctuation (optional, you can modify the regex pattern as needed)
    normalized_text = std::regex_replace(normalized_text, std::regex(R"([\.,!?;()\"'\-])"), "");

    // Remove extra whitespaces (replace multiple spaces with a single space)
    normalized_text = std::regex_replace(normalized_text, std::regex(R"(\s+)", std::regex::optimize), " ");

    // Trim leading and trailing whitespace
    if (!normalized_text.empty()) {
        normalized_text.erase(0, normalized_text.find_first_not_of(" \t\n\r"));
        normalized_text.erase(normalized_text.find_last_not_of(" \t\n\r") + 1);
    }

    return normalized_text;
}
