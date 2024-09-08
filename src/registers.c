// Implements functions that compute and manipulate the values stored
// in registers.

#include "registers.h"
#include <math.h>

void set_bit_8bit(uint8_t *dest, bool bit_val, int position)
{
    if (bit_val)
    {
        *dest |= 1 << position;
    }
    else
    {
        *dest &= ~(1 << position);
    }
}

void set_bit_16bit(uint16_t *dest, bool bit_val, int position)
{
    if (bit_val)
    {
        *dest |= 1 << position;
    }
    else
    {
        *dest &= ~(1 << position);
    }
}

bool compute_add_carry(int bit_position, uint32_t addend1, uint32_t addend2, uint32_t sum)
{
    return (addend1 ^ addend2 ^ sum) & (int)pow(2, bit_position + 1);
}