cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project(n3554_TestSuite)

set(CMAKE_CXX_FLAGS "-std=c++0x -g") # -std=c++0x is supported by g++-4.6 (-std=c++11 not)
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++0x -g -O0")

# Enable ExternalProject CMake module
include(ExternalProject)

# Set the build type if it isn't already
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# Add gtest
ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r 660
    TIMEOUT 10
    # Force separate output paths for debug and release builds to allow easy
    # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    # Disable update and install step
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/include)
include_directories(../include/)

file(GLOB_RECURSE ALL_TESTS
     alg.modifying.operations/*.cpp alg.nonmodifying/*.cpp alg.sorting/*.cpp)

# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
if(MSVC)
  set(Suffix ".lib")
else()
  set(Suffix ".a")
  set(Pthread "-pthread")
endif()

set(TEST_LIBS 
    debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix} 
    debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${Suffix}
    optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix} 
    optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${Suffix}
    ${Pthread})

enable_testing()

# standard algos
FOREACH (TEST ${ALL_TESTS})
  GET_FILENAME_COMPONENT(TESTNAME ${TEST} NAME_WE)
  add_executable(test_${TESTNAME} ${TEST})
  add_dependencies(test_${TESTNAME} googletest)
  target_link_libraries(test_${TESTNAME} ${TEST_LIBS})
  add_test(std::${TESTNAME} test_${TESTNAME})
ENDFOREACH(TEST)

# std::seq policy
FOREACH (TEST ${ALL_TESTS})
  GET_FILENAME_COMPONENT(TESTNAME ${TEST} NAME_WE)
  set(UNITTEST test-seq_${TESTNAME})
  add_executable(${UNITTEST} ${TEST})
  set_target_properties(${UNITTEST} PROPERTIES COMPILE_DEFINITIONS 
                        "EXECUTION_POLICY=std::parallel::policy::seq")
  add_dependencies(${UNITTEST} googletest)
  target_link_libraries(${UNITTEST} ${TEST_LIBS})
  add_test(seq-std::${TESTNAME} ${UNITTEST})
ENDFOREACH(TEST)




