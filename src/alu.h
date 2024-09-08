// Defines functions that are related to the duties of the
// CPU's ALU.

#ifndef ALU_H
#define ALU_H
#include <stdint.h>
#include "registers.h"

void add8(registers *p_registers, uint8_t addend);

#endif