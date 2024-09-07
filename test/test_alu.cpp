#include <gtest/gtest.h>
#include <stdint.h>
extern "C"
{
#include "../src/registers.h"
#include "../src/alu.h"
}

class add8_test: public ::testing::TestWithParam<
    std::tuple<registers, int, int, int>>
{};

TEST_P(add8_test, add8)
{
    auto params = GetParam();
    registers reg = std::get<0>(params);
    int addend = std::get<1>(params);
    int reg_a = std::get<2>(params);
    int reg_f = std::get<3>(params);

    int reg_bc = reg.bc;
    int reg_de = reg.de;
    int reg_hl = reg.hl;

    add8(&reg, addend);

    EXPECT_EQ(reg.a, reg_a);
    EXPECT_EQ(reg.f, reg_f);
    EXPECT_EQ(reg.bc, reg_bc);
    EXPECT_EQ(reg.de, reg_de);
    EXPECT_EQ(reg.hl, reg_hl);
}

INSTANTIATE_TEST_CASE_P(add8_test_cases,
    add8_test,
    testing::Values(
        std::make_tuple((registers){ .f = 0, .a = 0, .bc = 0, .de = 0, .hl = 0}, 0, 0, 128),
        std::make_tuple((registers){ .f = 0, .a = 0, .c = 0, .b = 1, .de = 0, .hl = 0}, 0, 1, 0),
        std::make_tuple((registers){ .f = 0, .a = 1, .c = 0, .b = 1, .de = 0, .hl = 0}, 1, 2, 0),
        std::make_tuple((registers){ .f = 0, .a = 8, .c = 0, .b = 12, .de = 0, .hl = 0}, 12, 20, 32),
        std::make_tuple((registers){ .f = 0, .a = 255, .c = 0, .b = 1, .de = 0, .hl = 0}, 1, 0, 176),
        std::make_tuple((registers){ .f = 0, .a = 240, .c = 0, .b = 50, .de = 0, .hl = 0}, 50, 34, 16),
        std::make_tuple((registers){ .f = 0, .a = 136, .c = 0, .b = 204, .de = 0, .hl = 0}, 204, 84, 48)
    ));