/*
Programmer: Chandler Teigen
Date Created: 1/20/2023
Date Modified: 1/20/2023
*/
#ifndef INSTRUCTION_DECODER_H 
#define INSTRUCTION_DECODER_H

#include "registers.h"


int decode(char* p_instruction, registers *p_registers, char *p_memory);

#endif