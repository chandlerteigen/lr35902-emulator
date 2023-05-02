/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#include <gtest/gtest.h>
#include "../src/registers.h"

TEST(test_registers, test_type_punning)
{
    registers reg = {
        .af = 0,
        .bc = 0,
        .de = 0,
        .hl = 0
        };
        
        // test 8 bit register values
        EXPECT_EQ(reg.a, 0);
        EXPECT_EQ(reg.f, 0);
        EXPECT_EQ(reg.b, 0);
        EXPECT_EQ(reg.c, 0);
        EXPECT_EQ(reg.d, 0);
        EXPECT_EQ(reg.e, 0);
        EXPECT_EQ(reg.h, 0);
        EXPECT_EQ(reg.l, 0);

        // test setting individual 8 bit registers
        reg.f = 1;
        EXPECT_EQ(reg.af, 1);
        EXPECT_EQ(reg.a, 0);

        reg.a = 1;
        EXPECT_EQ(reg.af, 257);
        EXPECT_EQ(reg.f, 1);

        reg.c = 1;
        EXPECT_EQ(reg.bc, 1);
        EXPECT_EQ(reg.b, 0);

        reg.b = 1;
        EXPECT_EQ(reg.bc, 257);
        EXPECT_EQ(reg.c, 1);

        reg.e = 1;
        EXPECT_EQ(reg.de, 1);
        EXPECT_EQ(reg.d, 0);

        reg.d = 1;
        EXPECT_EQ(reg.de, 257);
        EXPECT_EQ(reg.e, 1);

        reg.l = 1;
        EXPECT_EQ(reg.hl, 1);
        EXPECT_EQ(reg.h, 0);

        reg.h = 1;
        EXPECT_EQ(reg.hl, 257);
        EXPECT_EQ(reg.l, 1);

        // test overflow of 8 bit registers
        reg.f = 255;
        reg.f++;
        EXPECT_EQ(reg.f, 0);
        EXPECT_EQ(reg.a, 1);
        EXPECT_EQ(reg.af, 256);

        reg.a = 255;
        reg.a++;
        EXPECT_EQ(reg.a, 0);
        EXPECT_EQ(reg.f, 0);
        EXPECT_EQ(reg.af, 0);

        reg.c = 255;
        reg.c++;
        EXPECT_EQ(reg.c, 0);
        EXPECT_EQ(reg.b, 1);
        EXPECT_EQ(reg.bc, 256);

        reg.b = 255;
        reg.b++;
        EXPECT_EQ(reg.b, 0);
        EXPECT_EQ(reg.c, 0);
        EXPECT_EQ(reg.bc, 0);

        reg.e = 255;
        reg.e++;
        EXPECT_EQ(reg.e, 0);
        EXPECT_EQ(reg.d, 1);
        EXPECT_EQ(reg.de, 256);

        reg.d = 255;
        reg.d++;
        EXPECT_EQ(reg.d, 0);
        EXPECT_EQ(reg.e, 0);
        EXPECT_EQ(reg.de, 0);

        reg.l = 255;
        reg.l++;
        EXPECT_EQ(reg.l, 0);
        EXPECT_EQ(reg.h, 1);
        EXPECT_EQ(reg.hl, 256);

        reg.h = 255;
        reg.h++;
        EXPECT_EQ(reg.h, 0);
        EXPECT_EQ(reg.l, 0);
        EXPECT_EQ(reg.hl, 0);

        // test assigning via 16 bit registers
        reg.af = 257;
        EXPECT_EQ(reg.a, 1);
        EXPECT_EQ(reg.f, 1);

        reg.bc = 257;
        EXPECT_EQ(reg.b, 1);
        EXPECT_EQ(reg.c, 1);

        reg.de = 257;
        EXPECT_EQ(reg.d, 1);
        EXPECT_EQ(reg.e, 1);

        reg.hl = 257;
        EXPECT_EQ(reg.h, 1);
        EXPECT_EQ(reg.l, 1);

        // test 16 bit register overflow
        reg.af = 65535;
        reg.af++;
        EXPECT_EQ(reg.af, 0);
        EXPECT_EQ(reg.a, 0);
        EXPECT_EQ(reg.f, 0);

        reg.bc = 65535;
        reg.bc++;
        EXPECT_EQ(reg.bc, 0);
        EXPECT_EQ(reg.b, 0);
        EXPECT_EQ(reg.c, 0);

        reg.de = 65535;
        reg.de++;
        EXPECT_EQ(reg.de, 0);
        EXPECT_EQ(reg.d, 0);
        EXPECT_EQ(reg.e, 0);

        reg.hl = 65535;
        reg.hl++;
        EXPECT_EQ(reg.hl, 0);
        EXPECT_EQ(reg.h, 0);
        EXPECT_EQ(reg.l, 0);
}