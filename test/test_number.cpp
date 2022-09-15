#include "gtest/gtest.h"
#include "number.h"

TEST(HELLO, NUMB){
    EXPECT_EQ(add(1,2),3);
    EXPECT_NE(add(1,2),2);
}
