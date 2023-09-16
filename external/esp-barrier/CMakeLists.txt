cmake_minimum_required(VERSION 3.26)
project(esp_barrier)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        barrier
        URL https://github.com/debauchee/barrier/archive/refs/tags/v2.4.0.zip
)

FetchContent_Declare(
        ArduinoFake
        GIT_REPOSITORY https://github.com/FabioBatSilva/ArduinoFake.git
        GIT_TAG master
)

FetchContent_Populate(barrier)

file(COPY ${barrier_SOURCE_DIR}/src/lib/barrier/protocol_types.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/barrier)
file(COPY ${barrier_SOURCE_DIR}/src/lib/barrier/protocol_types.cpp DESTINATION ${PROJECT_SOURCE_DIR}/lib/barrier)
file(COPY ${barrier_SOURCE_DIR}/src/lib/barrier/ProtocolUtil.cpp DESTINATION ${PROJECT_SOURCE_DIR}/lib/barrier)
file(COPY ${barrier_SOURCE_DIR}/src/lib/barrier/ProtocolUtil.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/barrier)
file(COPY ${barrier_SOURCE_DIR}/src/lib/barrier/XBarrier.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/barrier)
file(COPY ${barrier_SOURCE_DIR}/src/lib/barrier/XBarrier.cpp DESTINATION ${PROJECT_SOURCE_DIR}/lib/barrier)

file(COPY ${barrier_SOURCE_DIR}/src/lib/common/basic_types.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/common)
file(COPY ${barrier_SOURCE_DIR}/src/lib/common/stdmap.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/common)
file(COPY ${barrier_SOURCE_DIR}/src/lib/common/stdvector.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/common)
file(COPY ${barrier_SOURCE_DIR}/src/lib/common/stdpre.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/common)
file(COPY ${barrier_SOURCE_DIR}/src/lib/common/stdlist.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/common)
file(COPY ${barrier_SOURCE_DIR}/src/lib/common/stdpost.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/common)

file(COPY ${barrier_SOURCE_DIR}/src/lib/base/Event.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)
file(COPY ${barrier_SOURCE_DIR}/src/lib/base/Event.cpp DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)
file(COPY ${barrier_SOURCE_DIR}/src/lib/base/EventTypes.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)
file(COPY ${barrier_SOURCE_DIR}/src/lib/base/ELevel.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)
file(COPY ${barrier_SOURCE_DIR}/src/lib/base/XBase.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)
file(COPY ${barrier_SOURCE_DIR}/src/lib/base/XBase.cpp DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)
file(COPY ${barrier_SOURCE_DIR}/src/lib/base/ILogOutputter.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/base)

file(COPY ${barrier_SOURCE_DIR}/src/lib/io/XIO.h DESTINATION ${PROJECT_SOURCE_DIR}/lib/io)
file(COPY ${barrier_SOURCE_DIR}/src/lib/io/XIO.cpp DESTINATION ${PROJECT_SOURCE_DIR}/lib/io)

FetchContent_MakeAvailable(ArduinoFake)

include_directories (src)
include_directories (lib)
include_directories(${ArduinoFake_SOURCE_DIR}/src)
include_directories(${ArduinoFake_SOURCE_DIR}/src/Arduino)

add_subdirectory(lib)
add_library(esp_barrier
        src/library.cpp
        src/base/String.cpp
        src/base/Log.cpp
        src/base/ConsoleLogOutputter.cpp
        src/common/Version.cpp
)

add_subdirectory(tests)

target_link_libraries(esp_barrier barrier base io)
