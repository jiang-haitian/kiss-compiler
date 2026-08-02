cmake_minimum_required(VERSION 3.20.0)
project(kiss-compiler LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to conform to")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(LLVM REQUIRED CONFIG)
find_package(MLIR REQUIRED CONFIG)
find_package(Polly REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")
message(STATUS "Using PollyConfig.cmake in: ${Polly_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
include_directories(SYSTEM ${MLIR_INCLUDE_DIRS})

include(AddLLVM)
include(AddMLIR)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM ${CMAKE_CURRENT_BINARY_DIR}/include) # Tablegen'd files

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(tools)
