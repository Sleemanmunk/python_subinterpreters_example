cmake_minimum_required(VERSION 3.4)
project(python_subinterpreters)

find_package(Python COMPONENTS Development)
find_package(Threads REQUIRED)

SET(PYTHON_VERSION 3.9)
SET(PYTHON_ENV /deployment/envs/bert_sentiment)

#include_directories( ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
#link_libraries(${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so)


add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME}  PUBLIC cxx_std_11)
target_include_directories(${PROJECT_NAME} PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(${PROJECT_NAME}  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so Threads::Threads)

