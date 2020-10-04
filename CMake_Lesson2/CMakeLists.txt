cmake_minimum_required(VERSION 2.8.9)
project(cmake_sharedlib)
set(CMAKE_BUILD_TYPE Release)

#Bring the headers into the project
include_directories(crypto_lib_src/Inc)

#Can manually add the sources using the set command as follows:


#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "crypto_lib_src/Src/*.c")

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
add_library(testCrypto SHARED ${SOURCES})
install(TARGETS testCrypto DESTINATION /usr/lib) 