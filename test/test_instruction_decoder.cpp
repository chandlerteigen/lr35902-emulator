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
}



TEST(test_instruction_decoder, test_nop)
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