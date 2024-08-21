set(sources
    test_registers.cpp
    test_instruction_decoder.cpp
)

add_executable(lr35902_emulator_tests ${sources})
target_link_libraries(lr35902_emulator_tests PUBLIC
    gtest_main
    lr35902_emulator 
)

add_test(
    NAME lr35902_emulator_tests
    COMMAND lr35902_emulator_tests
)
