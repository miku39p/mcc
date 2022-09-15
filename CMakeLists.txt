cmake_minimum_required(VERSION 3.13)
project(mcc)

set(CMAKE_CXX_STANDARD 14)
set(MCC_INCLUDE_DIRS include/)
set(THRDPARTY_INCLUDE_DIRS thrdparty/include/)
set(GTEST_LIB
    "libgtest_main.so"
    "libgtest.so")
set(THRDPARTY_LINK_DIRS thrdparty/lib/gtest)
file(GLOB_RECURSE MCC_SOURCE src/*.cpp)


add_library(mcc SHARED ${MCC_SOURCE})
target_include_directories(mcc PUBLIC ${MCC_INCLUDE_DIRS})

set(MAIN_FILES test/test_number.cpp)
add_executable(test  ${MAIN_FILES})


target_include_directories(test PUBLIC ${THRDPARTY_INCLUDE_DIRS} PUBLIC ${MCC_INCLUDE_DIRS})
target_link_directories(test PUBLIC ${THRDPARTY_LINK_DIRS}  PUBLIC "./build/")

target_link_libraries(test LINK_PUBLIC mcc LINK_PUBLIC ${GTEST_LIB})

# target_include_directories(test INTERFACE ${THRDPARTY_INCLUDE_DIRS})
# link_directories(${THRDPARTY_LINK_DIRS})
# link_directories(build/)
# link_libraries(test "libmcc.so" ${GTEST_LIB})
