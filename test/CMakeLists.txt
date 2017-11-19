# Make test executable
set(TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/runtests.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test_sequence_iterator.cpp)
add_executable(runtests ${TEST_SOURCES})

target_link_libraries(runtests
  Catch
  Seqalgo)
