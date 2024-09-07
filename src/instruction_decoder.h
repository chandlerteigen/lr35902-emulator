/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#ifndef INSTRUCTION_DECODER_H 
#define INSTRUCTION_DECODER_H

#include <stdint.h>
#include "registers.h" 


int decode(registers* const p_registers, uint8_t* const p_memory);

#endif