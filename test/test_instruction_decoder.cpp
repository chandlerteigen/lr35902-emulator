/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#include <gtest/gtest.h>
extern "C"
{
#include "../src/registers.h"
#include "../src/instruction_decoder.h"
}

TEST(test_instruction_decoder, test_instructions)
{
    registers reg = {0};

    char instruction[] = {'\0'};

    char* const p_memory = 0;
    char* const p_stack = 0;
    int cycles = 0;
    
    cycles = decode(instruction, &reg, p_memory, p_stack);

    // all register values should remain the same
    EXPECT_EQ(reg.af, 0);
    EXPECT_EQ(reg.bc, 0);
    EXPECT_EQ(reg.de, 0);
    EXPECT_EQ(reg.hl, 0);

    EXPECT_EQ(cycles, 4);
}
