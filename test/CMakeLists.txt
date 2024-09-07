set(sources
    test_registers.cpp
    test_alu.cpp
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

set(mock_lib_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/instruction_decoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/registers.c
)
set(mock_lib_headers
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/instruction_decoder.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/registers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/alu.h

)

set(sources_mock
    test_instruction_decoder.cpp
)

add_library(lr35902_emulator_mock STATIC ${mock_lib_sources} ${mock_lib_headers})

add_executable(lr35902_emulator_mock_tests ${sources_mock})

target_link_libraries(lr35902_emulator_mock_tests PUBLIC
    gtest_main
    lr35902_emulator_mock
)

add_test(
    NAME lr35902_emulator_mock_tests
    COMMAND lr35902_emulator_mock_tests
)