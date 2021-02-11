cmake_minimum_required(VERSION 3.17)
project(os_hw5 C)

set(CMAKE_C_STANDARD 99)

add_executable(os_hw5 main.c queue.h queue.c process.h multilevelFeedbackQueue.h multilevelFeedbackQueue.c)