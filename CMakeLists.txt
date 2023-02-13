cmake_minimum_required(VERSION 3.16...3.23)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ENABLE_DEVELOPER_MODE
    TRUE
    CACHE BOOL "Enable 'developer mode'")

# Change this to false if you want to disable warnings_as_errors in developer mode
set(WARNINGS_AS_ERRORS TRUE)
set(ProjectOptions_SRC_DIR
    ${CMAKE_CURRENT_LIST_DIR}
    CACHE FILEPATH "")

project(
    ProjectName
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "%%myurl%%"
  LANGUAGES CXX C)

# This variable is set by project() in CMake 3.21+
string(
  COMPARE EQUAL
          "${CMAKE_SOURCE_DIR}"
          "${PROJECT_SOURCE_DIR}"
          PROJECT_IS_TOP_LEVEL)

include(CTest)

# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-fdiagnostics-color=always)

# standard compiler warnings
if("${GCC_WARNINGS}" STREQUAL "")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast -Werror")
  #if(WARNINGS_AS_ERRORS)
  #  list(APPEND GCC_WARNINGS "-Werror")
  #endif()
endif()

# sanitizer options if supported by compiler
if(${ENABLE_SANITIZER})
    set(SANITIZERS address leak undifined)
list(
  JOIN
  SANITIZERS
  ","
  LIST_OF_SANITIZERS)
      target_compile_options(${project_name} INTERFACE -fsanitize=${LIST_OF_SANITIZERS})
      target_link_options(${project_name} INTERFACE -fsanitize=${LIST_OF_SANITIZERS})
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_subdirectory(src)
add_subdirectory(test)
