cmake_minimum_required(VERSION 3.31)
project(textcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(python_package src/textcpp/sub.cpp
        src/textcpp/add.cpp
        src/textcpp/operations.h
        src/textcpp/bindings_text_utils.cpp
        src/textcpp/bindings.h
        src/textcpp/count_words.cpp
        src/textcpp/count_words.h
        src/textcpp/bindings_others.cpp
        src/textcpp/text_utils/frequency_count.cpp
)
