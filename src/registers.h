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
        int16_t af;
        struct
        {
            int8_t f;
            int8_t a;
        };
    };

    union
    {
        int16_t bc;
        struct
        {
            int8_t c;
            int8_t b;
        };
    };

    union
    {
        int16_t de;
        struct
        {
            int8_t e;
            int8_t d;
        };
    };

    union
    {
        int16_t hl;
        struct
        {
            int8_t l;
            int8_t h;
        };
    };
} registers;

#endif