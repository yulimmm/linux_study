file(GLOB LIB_SOURCE "print/*.cpp" "print/*.h")
file(GLOB ADD_SOURCE "add/*.cpp" "add/*.h")

add_library(print_lib ${LIB_SOURCE})
target_include_directories(print_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/print")

add_library(add_lib ${ADD_SOURCE})
target_include_directories(add_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/add")
