// Defines the functions related to decoding instructions from
// the program binary.

#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include <stdint.h>
#include "registers.h"

int decode(registers *const p_registers, uint8_t *const p_memory);

#endif