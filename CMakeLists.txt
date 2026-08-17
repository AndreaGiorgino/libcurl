cmake_minimum_required(VERSION 3.24)

project(
    curl
    VERSION 1.0.0
    LANGUAGES CXX
)

#
# Dependencies
#

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/Options.cmake)

find_package(CURL QUIET)

if(NOT CURL_FOUND)
    message(STATUS "Fetching CURL.")
    include(FetchContent)
    FetchContent_Declare(
        CURL
        GIT_REPOSITORY git@github.com:curl/curl
        GIT_TAG curl-8_21_0
        GIT_SHALLOW TRUE
    )

    set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
    set(HTTP_ONLY ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(CURL)
endif()

#
# Target
#

file(
    GLOB_RECURSE SOURCE_FILES
    CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx
)

add_library(
    ${PROJECT_NAME}
    STATIC ${SOURCE_FILES}
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE -Wextra -Wall -pedantic
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

if(TARGET CURL::libcurl)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE CURL::libcurl
    )
else()
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE libcurl
    )
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/PostBuild.cmake)

if(CURL_BUILD_EXAMPLE)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/example)
endif()
