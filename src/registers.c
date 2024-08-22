/*
Programmer: Chandler Teigen
Date Created: 8/22/2024
Date Modified: 8/22/2024
*/

#include "registers.h"
#include <math.h>

bool compute_add_carry(int bit_position, uint32_t addend1, uint32_t addend2, uint32_t sum)
{
    return (addend1 ^ addend2 ^ sum) & (int)pow(2, bit_position + 1);
}