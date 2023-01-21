#include "instruction_decoder.h"


int decode(char *p_instruction, registers *p_registers, char *p_memory)
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
            cycles = 1; 
            break;
    }

    return cycles;
}
