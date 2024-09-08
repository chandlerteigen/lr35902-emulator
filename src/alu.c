// Implements functions that are related to the duties of the
// CPU's ALU.

#include "alu.h"

void add8(registers *p_registers, uint8_t addend)
{
    uint8_t sum = p_registers->a + p_registers->b;
    uint8_t flags = 0;
    if (sum < p_registers->a)
    {
        flags = flags + C_FLAG_VAL;
    }
    if (compute_add_carry(3, p_registers->a, p_registers->b, sum))
    {
        flags = flags + H_FLAG_VAL;
    }
    if (sum == 0)
    {
        flags = flags + Z_FLAG_VAL;
    }

    p_registers->a = sum;
    p_registers->f = flags;
}