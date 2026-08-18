cmake_minimum_required(VERSION 3.24)

#
# Dependencies
#

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY git@github.com:AndreaGiorgino/libjson
    GIT_TAG 1.2.0
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(json)

#
# Target executables
#

set(
    SOURCE_FILES

    # Methods
    TestMethods_GetName.cxx

    # Headers
    TestHeaders_GetName.cxx

    # Status codes
    TestStatusCodes_GetName.cxx

    # Requuest
    TestRequest_Ctors.cxx
    TestRequest_GetSet.cxx
    TestRequest_Headers.cxx
    TestRequest_Parameters.cxx

    # Response
    TestResponse_Ctors.cxx
    TestResponse_GetSet.cxx

    # GET
    TestGET.cxx
)

create_test_sourcelist(
    TEST_SOURCELIST CommonCxxTests.cxx
    ${SOURCE_FILES}
)

#
# Target
#

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    CommonCxxTests
    ${TEST_SOURCELIST} helpers.cxx
)

set_target_properties(
    CommonCxxTests
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_compile_options(
    CommonCxxTests
    PRIVATE -Wextra -Wall -pedantic
)

target_include_directories(
    CommonCxxTests
    PRIVATE $<TARGET_FILE_DIR:${PROJECT_NAME}>/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
    CommonCxxTests
    PRIVATE ${PROJECT_NAME}
    PRIVATE json
)

foreach(TEST_FILE ${SOURCE_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_test(
        NAME ${TEST_NAME}
        COMMAND CommonCxxTests ${TEST_NAME}
    )
endforeach()

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/PostBuild.cmake)
