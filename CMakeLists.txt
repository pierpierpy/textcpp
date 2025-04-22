cmake_minimum_required(VERSION 3.31)
project(textcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(textcpp
        src/textcpp/others/sub.cpp
        src/textcpp/others/add.cpp
        src/textcpp/operations.h
        src/textcpp/text_utils/bindings_text_utils.cpp
        src/textcpp/text_utils/count_words.cpp
        src/textcpp/text_utils/frequency_count.cpp
        src/textcpp/others/bindings_others.cpp
)
