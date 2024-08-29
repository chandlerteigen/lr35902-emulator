/*
Programmer: Chandler Teigen
Date Created: 5/1/2023
Date Modified: 5/1/2023
*/
#include <gtest/gtest.h>
#include <stdbool.h>
extern "C"
{
#include "../src/registers.h"
}

//void set_bit_8bit(uint8_t *dest, bool bit_val, int position);

class flag_test: public ::testing::TestWithParam<
    std::tuple<uint8_t, bool, int, uint8_t>>
{};

TEST_P(flag_test, test_set_bit_8bit)
{
    auto params = GetParam();
    uint8_t reg = std::get<0>(params);
    const bool bit_val = std::get<1>(params);
    const int bit_pos = std::get<2>(params);
    const uint8_t result = std::get<3>(params);

    set_bit_8bit(&reg, bit_val, bit_pos);

    EXPECT_EQ(reg, result);
}

INSTANTIATE_TEST_CASE_P(test_set_bit_8bit_test_cases, 
    flag_test,
    testing::Values(
        std::make_tuple(0, true, 0, 1),
        std::make_tuple(0, false, 0, 0),
        std::make_tuple(0, true, 1, 2),
        std::make_tuple(8, false, 3, 0),
        std::make_tuple(127, false, 3, 119),
        std::make_tuple(127, true, 5, 127),
        std::make_tuple(127, true, 6, 127)
    ));

class add_carry_test: public ::testing::TestWithParam<
    std::tuple<uint32_t, uint32_t, uint32_t, int, bool>>
{};

TEST_P(add_carry_test, test_compute_add_carry)
{
    auto params = GetParam();
    const uint32_t addend1 = std::get<0>(params);
    const uint32_t addend2 = std::get<1>(params);
    const uint32_t sum = std::get<2>(params);
    const int bit_position = std::get<3>(params);
    const bool expected_carry = std::get<4>(params);

    bool carry = false;
    carry = compute_add_carry(bit_position, addend1, addend2, sum);

    EXPECT_EQ(carry, expected_carry);
}

INSTANTIATE_TEST_CASE_P(compute_add_carry_test_cases, 
    add_carry_test,
    testing::Values(
        std::make_tuple(0, 0, 0, 3, false),
        std::make_tuple(1, 1, 2, 0, true),
        std::make_tuple(1, 1, 2, 1, false),
        std::make_tuple(8, 16, 24, 3, false),
        std::make_tuple(7, 9, 16, 3, true)
    ));

TEST(test_registers, test_type_punning)
{
    registers reg = {0};

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