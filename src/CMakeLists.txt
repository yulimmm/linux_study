file(GLOB SRC_FILES "*.cpp")

add_executable(MyApp ${SRC_FILES})
target_link_libraries(MyApp print_lib)
target_link_libraries(MyApp add_lib)