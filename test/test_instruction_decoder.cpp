/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#include <gtest/gtest.h>
#include <stdint.h>
extern "C"
{
#include "../src/registers.h"
#include "../src/instruction_decoder.h"
#include "../fff/fff.h"
DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(add8, registers *, uint8_t);
}


TEST(test_instruction_decoder, test_nop_instruction)
{
    uint8_t program[] = {'\0', '\0'};
    registers reg = {0};
    reg.program_counter = program;

    uint8_t* const p_memory = 0;
    uint8_t* const p_stack = 0;
    int cycles = 0;
    
    cycles = decode(&reg, p_memory);

    // all register values should remain the same
    EXPECT_EQ(reg.af, 0);
    EXPECT_EQ(reg.bc, 0);
    EXPECT_EQ(reg.de, 0);
    EXPECT_EQ(reg.hl, 0);
    // program pointer should be incremented by 1
    EXPECT_EQ(reg.program_counter - program, 1);
    EXPECT_EQ(cycles, 4);
}

class add_8bit_instruction_test: public ::testing::TestWithParam<
    std::tuple<registers, uint8_t *, uint8_t, int>>
{};

TEST_P(add_8bit_instruction_test, add_8bit_instruction)
{
    auto params = GetParam();
    registers reg = std::get<0>(params);
    uint8_t *p_memory = std::get<1>(params);
    uint8_t add8_addend = std::get<2>(params);
    int expected_cycles = std::get<3>(params);

    uint8_t *initial_program_counter = reg.program_counter;

    int cycles = decode(&reg, p_memory);

    EXPECT_EQ(add8_fake.arg0_val, &reg);
    EXPECT_EQ(add8_fake.arg1_val, add8_addend);
    EXPECT_EQ(reg.program_counter - initial_program_counter, 1);
    EXPECT_EQ(cycles, expected_cycles);
}
uint8_t program[] = { 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87 };
uint8_t memory[] = { 100, 101, 102, 103, 104, 105};

INSTANTIATE_TEST_CASE_P(add_8bit_instruction_test_cases,
    add_8bit_instruction_test,
    testing::Values(
        std::make_tuple((registers){ .program_counter = program, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 2, 4),
        std::make_tuple((registers){ .program_counter = program + 1, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 3, 4),
        std::make_tuple((registers){ .program_counter = program + 2, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 4, 4),
        std::make_tuple((registers){ .program_counter = program + 3, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 5, 4),
        std::make_tuple((registers){ .program_counter = program + 4, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 6, 4),
        std::make_tuple((registers){ .program_counter = program + 5, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 7, 4),
        std::make_tuple((registers){ .program_counter = program + 6, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .hl = 0 }, memory, 100, 8),
        std::make_tuple((registers){ .program_counter = program + 6, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .hl = 1 }, memory, 101, 8),
        std::make_tuple((registers){ .program_counter = program + 6, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .hl = 2 }, memory, 102, 8),
        std::make_tuple((registers){ .program_counter = program + 6, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .hl = 3 }, memory, 103, 8),
        std::make_tuple((registers){ .program_counter = program + 6, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .hl = 4 }, memory, 104, 8),
        std::make_tuple((registers){ .program_counter = program + 7, .f = 1, .a = 0, .c = 3, .b = 2, .e = 5, .d = 4, .l = 7, .h = 6 }, memory, 0, 4)
    ));