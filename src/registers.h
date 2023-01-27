/*
Programmer: Chandler Teigen
Date Created: 1/20/2023
Date Modified: 1/20/2023
*/
#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdint.h>

typedef struct registers
{
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

#endif