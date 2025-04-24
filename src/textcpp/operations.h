#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "preprocessing/tokenizer.h"
#include "preprocessing/stopword_utils.h"
#include "text_utils/read.h"

int add(int a, int b);
int sub(int a, int b);
int count_words(const std::string& input);
int  word_frequency_count(const std::string& path, std::string word);

std::unordered_map<std::string, int>  frequency_count(const std::string& path);
std::unordered_map<std::string, int> extract_ngrams(const std::string& input, int n, const Tokenizer& tokenizer, bool is_file = false,bool normalize = false);
std::vector<std::string> remove_stopwords(const std::vector<std::string>& tokens,const std::unordered_set<std::string>& stopwords);
std::string normalize_text(const std::string& text);
std::string read_text(const std::string& file_path);
#endif
