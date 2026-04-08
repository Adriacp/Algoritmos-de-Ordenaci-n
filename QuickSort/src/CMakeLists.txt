cmake_minimum_required(VERSION 3.10)

project(ProductorConsumidor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recoge todos los .cpp del directorio
file(GLOB SOURCES "*.cpp")

# Crea el ejecutable
add_executable(main ${SOURCES})