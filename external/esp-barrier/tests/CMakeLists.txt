include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
        test.cpp
)

add_executable(esp_barrier_tests ${TEST_SOURCES})

target_include_directories(esp_barrier_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(esp_barrier_tests gtest gtest_main esp_barrier ArduinoFake)