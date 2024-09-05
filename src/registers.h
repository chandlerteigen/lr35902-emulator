/*
Programmer: Chandler Teigen
Date Created: 1/20/2023
Date Modified: 1/20/2023
*/
#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdint.h>
#include <stdbool.h>

#define Z_FLAG_POS 7
#define N_FLAG_POS 6
#define H_FLAG_POS 5
#define C_FLAG_POS 4

#define Z_FLAG_VAL (uint8_t)128 
#define N_FLAG_VAL (uint8_t)64
#define H_FLAG_VAL (uint8_t)32
#define C_FLAG_VAL (uint8_t)16


typedef struct registers
{   
    uint8_t *stack_pointer;

    uint8_t *program_counter;

    union
    {
        uint16_t af;
        struct
        {
            uint8_t f;
            uint8_t a;
        };
    };

    union
    {
        uint16_t bc;
        struct
        {
            uint8_t c;
            uint8_t b;
        };
    };

    union
    {
        uint16_t de;
        struct
        {
            uint8_t e;
            uint8_t d;
        };
    };

    union
    {
        uint16_t hl;
        struct
        {
            uint8_t l;
            uint8_t h;
        };
    };
} registers;

void set_bit_8bit(uint8_t *dest, bool bit_val, int position);

void set_bit_16bit(uint16_t *dest, bool bit_val, int position);

bool compute_add_carry(int bit_position, uint32_t addend1, uint32_t addend2, uint32_t sum);

#endif