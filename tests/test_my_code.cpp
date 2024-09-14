// tests/test_my_code.cpp
#include <gtest/gtest.h>
#include "my_header.h"

TEST(AdditionTest, HandlesPositiveInput) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(10, 15), 25);
    EXPECT_EQ(add(10, 2), 12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

