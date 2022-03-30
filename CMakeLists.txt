cmake_minimum_required(VERSION 3.4)
project(python_subinterpreters)

SET(PYTHON_VERSION 3.9) #Set this to your version of python
SET(PYTHON_ENV /deployment/envs/bert_sentiment) #point this to your python home path

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME}  PUBLIC cxx_std_11)
target_include_directories(${PROJECT_NAME} PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(${PROJECT_NAME}  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so)

