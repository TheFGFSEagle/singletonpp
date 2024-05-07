add_executable(test-basic basic.cxx)
target_link_libraries(test-basic singleton++)
add_test(NAME Basic COMMAND test-basic)

