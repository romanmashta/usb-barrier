file(GLOB headers "*.h")
file(GLOB sources "*.cpp")

list(APPEND sources ${headers})

add_library(base STATIC ${sources})
