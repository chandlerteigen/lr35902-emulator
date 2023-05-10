/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#include "instruction_decoder.h"

int decode(char* const p_instruction, registers* const p_registers, char* const p_memory, char* const p_stack)
{
    char opcode = *p_instruction;
    int cycles = 0;

    switch(opcode)
    {
        // Instruction: NOP
        // Bytes: 1
        // Cycles: 4
        // Affected Registers: - - - -
        case 0x00:
            cycles = 4; 
            break;
    }

    return cycles;
}
