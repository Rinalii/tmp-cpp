#include <gtest/gtest.h>
#include "task_b/solution.h"

TEST(TaskB, Example1) {
    EXPECT_EQ(BuildMinPSP(6, "()[]", "([("), "([()])");
}
TEST(TaskB, Example2) {
    EXPECT_EQ(BuildMinPSP(6, "][)(", "(["), "([][])");
}
TEST(TaskB, Example3) {
    EXPECT_EQ(BuildMinPSP(4, "(][)", "()["), "()[]");
}