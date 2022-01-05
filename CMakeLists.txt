cmake_minimum_required(VERSION 3.21)
project(matplotplusplus_TEST17)

set(CMAKE_CXX_STANDARD 17)

find_package(matplotplusplus QUIET)
if(NOT matplotplusplus_FOUND)
    include(FetchContent)
    FetchContent_Declare(matplotplusplus
            GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
            GIT_TAG origin/master) # or whatever tag you want

    FetchContent_GetProperties(matplotplusplus)
    if(NOT matplotplusplus_POPULATED)
        FetchContent_Populate(matplotplusplus)

        add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()

find_package(csv-parser QUIET)
if(NOT csv-parser_FOUND)
    include(FetchContent)
    FetchContent_Declare(csv-parser
            GIT_REPOSITORY https://github.com/vincentlaucsb/csv-parser)

    FetchContent_GetProperties(csv-parser)
    if(NOT csv-parser_POPULATED)
        FetchContent_Populate(csv-parser)

        add_subdirectory(${csv-parser_SOURCE_DIR} ${csv-parser_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()

#add_subdirectory(csv-parser)

add_executable(matplotplusplus_TEST17 main.cpp)
target_link_libraries(matplotplusplus_TEST17
                      csv
                      matplot)