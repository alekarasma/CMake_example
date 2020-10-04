cmake_minimum_required(VERSION 2.8.9)
project(cmake_sharedlib)
set(CMAKE_BUILD_TYPE Release)

#Bring the headers into the project
include_directories(crypto_lib_src/Inc)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "crypto_lib_src/Src/*.c")

#instead od add_executable use add_library to create library
# use SHARED flag to create shared library .so
#This will create libtestCrypto.so ib build/ folder
add_library(testCrypto SHARED ${SOURCES}):

#use STATIC keyword to create static library .a
#This will create libtestCrypto.a ib build/ folder
#add_library(testCrypto STATIC ${SOURCES}):

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS testCrypto DESTINATION /usr/lib) 