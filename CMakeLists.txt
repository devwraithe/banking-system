cmake_minimum_required(VERSION 3.10)

# Project name
project(BankingSystem)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the executable
add_executable(BankingSystem
        src/main.cpp
        src/account.cpp
        src/bank.cpp
)