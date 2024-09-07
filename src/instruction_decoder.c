/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#include "instruction_decoder.h"
#include "alu.h"

int decode(registers* const p_registers, uint8_t* const p_memory)
{
    uint8_t opcode = *p_registers->program_counter;
    int cycles = 0;
    int bytes = 0;

    switch(opcode)
    {
        // NOP - 1b, 4c, ----
        case 0x00:
            cycles = 4;
            bytes = 1;
            break;

        // ADD A, B - 1b, 4c, Z0HC
        case 0x80:
            add8(p_registers, p_registers->b);
            cycles = 4;
            bytes = 1;  
            break;
        // ADD A, C - 1b, 4c, Z0HC
        case 0x81:
            add8(p_registers, p_registers->c);
            cycles = 4;
            bytes = 1;  
            break;
        // ADD A, D - 1b, 4c, Z0HC
        case 0x82:
            add8(p_registers, p_registers->d);
            cycles = 4;
            bytes = 1;  
            break;
        // ADD A, E - 1b, 4c, Z0HC
        case 0x83:
            add8(p_registers, p_registers->e);
            cycles = 4;
            bytes = 1;  
            break;
        // ADD A, H - 1b, 4c, Z0HC
        case 0x84:
            add8(p_registers, p_registers->h);
            cycles = 4;
            bytes = 1;  
            break;
        // ADD A, L - 1b, 4c, Z0HC
        case 0x85:
            add8(p_registers, p_registers->l);
            cycles = 4;
            bytes = 1;  
            break;
        // ADD A, [HL] - 1b, 8c, Z0HC
        case 0x86:
            add8(p_registers, *(p_memory + p_registers->hl));
            cycles = 8;
            bytes = 1;  
            break;
        // ADD A, A - 1b, 4c, Z0HC
        case 0x87:
            add8(p_registers, p_registers->a);
            cycles = 4;
            bytes = 1;  
            break;
    }

    p_registers->program_counter = p_registers->program_counter + bytes;
    return cycles;
}
