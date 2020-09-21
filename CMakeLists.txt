cmake_minimum_required(VERSION 2.8.9)
project(cryptocmake_test)

#Bring the headers into the project
include_directories(crypto_lib_src/Inc)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "crypto_lib_src/Src/*.c")
file(GLOB SOURCES1 "project_src/*.c")

add_executable(crpto_test ${SOURCES} ${SOURCES1}) 