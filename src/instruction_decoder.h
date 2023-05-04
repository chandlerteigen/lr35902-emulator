/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#ifndef INSTRUCTION_DECODER_H 
#define INSTRUCTION_DECODER_H

#include "registers.h"


int decode(char* const p_instruction, registers* const p_registers, char* const p_memory);

#endif