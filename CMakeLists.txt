cmake_minimum_required(VERSION 3.31)
project(textcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(textcpp
        src/textcpp/others/*.cpp
        src/textcpp/others/*.h

        src/textcpp/text_utils/*.cpp
        src/textcpp/text_utils/*.h
        
        src/textcpp/preprocessing/*.cpp
        src/textcpp/preprocessing/*.h
        
        src/textcpp/operations.h
)
