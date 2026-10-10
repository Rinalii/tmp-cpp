#include <gtest/gtest.h>
#include "task_a/solution.h"

// ---------- Пустая строка ----------
TEST(TaskA, EmptyStringIsCorrect) {
    EXPECT_TRUE(IsCorrectBracketSequence(""));
}

// ---------- Простые корректные пары ----------
TEST(TaskA, SinglePairs) {
    EXPECT_TRUE(IsCorrectBracketSequence("()"));
    EXPECT_TRUE(IsCorrectBracketSequence("[]"));
    EXPECT_TRUE(IsCorrectBracketSequence("{}"));
}

// ---------- Конкатенация корректных ----------
TEST(TaskA, Concatenation) {
    EXPECT_TRUE(IsCorrectBracketSequence("()[]{}"));
    EXPECT_TRUE(IsCorrectBracketSequence("()()()"));
    EXPECT_TRUE(IsCorrectBracketSequence("{}[]()"));
}

// ---------- Вложенность ----------
TEST(TaskA, Nesting) {
    EXPECT_TRUE(IsCorrectBracketSequence("([{}])"));
    EXPECT_TRUE(IsCorrectBracketSequence("{[()]}"));
    EXPECT_TRUE(IsCorrectBracketSequence("(((())))"));
    EXPECT_TRUE(IsCorrectBracketSequence("{[({})]}"));
}

// ---------- Несовпадение типа скобок ----------
TEST(TaskA, MismatchedTypes) {
    EXPECT_FALSE(IsCorrectBracketSequence("([)]"));
    EXPECT_FALSE(IsCorrectBracketSequence("{(})"));
    EXPECT_FALSE(IsCorrectBracketSequence("[(])"));
}

// ---------- Лишняя закрывающая ----------
TEST(TaskA, ExtraClosing) {
    EXPECT_FALSE(IsCorrectBracketSequence(")"));
    EXPECT_FALSE(IsCorrectBracketSequence("())"));
    EXPECT_FALSE(IsCorrectBracketSequence("()]"));
    EXPECT_FALSE(IsCorrectBracketSequence("]["));
}

// ---------- Лишняя открывающая ----------
TEST(TaskA, ExtraOpening) {
    EXPECT_FALSE(IsCorrectBracketSequence("("));
    EXPECT_FALSE(IsCorrectBracketSequence("(()"));
    EXPECT_FALSE(IsCorrectBracketSequence("([{"));
    EXPECT_FALSE(IsCorrectBracketSequence("{}("));
}

// ---------- Закрывающая в самом начале ----------
TEST(TaskA, CloseBeforeOpen) {
    EXPECT_FALSE(IsCorrectBracketSequence(")("));
    EXPECT_FALSE(IsCorrectBracketSequence("][()"));
    EXPECT_FALSE(IsCorrectBracketSequence("}()"));
}

// ---------- Граничные случаи по длине ----------
TEST(TaskA, MaxDepthBalanced) {
    constexpr int n = 100000;
    std::string s;
    s.reserve(n * 2);
    for (int i = 0; i < n; ++i) s += '(';
    for (int i = 0; i < n; ++i) s += ')';
    EXPECT_TRUE(IsCorrectBracketSequence(s));
}

TEST(TaskA, MaxDepthUnbalanced) {
    constexpr int n = 100000;
    std::string s;
    s.reserve(n + 1);
    for (int i = 0; i < n; ++i) s += '(';
    s += ')';                       // на одну закрывающую меньше
    EXPECT_FALSE(IsCorrectBracketSequence(s));
}

TEST(TaskA, MaxLengthAlternating) {
    constexpr int n = 100000;
    std::string s;
    s.reserve(n);
    for (int i = 0; i < n / 2; ++i) s += "()";
    EXPECT_TRUE(IsCorrectBracketSequence(s));
}

class TaskAParam : public ::testing::TestWithParam<std::tuple<std::string, bool>> {};

TEST_P(TaskAParam, MatchesExpected) {
    const auto& [input, expected] = GetParam();
    EXPECT_EQ(IsCorrectBracketSequence(input), expected) << "input = \"" << input << "\"";
}

INSTANTIATE_TEST_SUITE_P(
    Cases,
    TaskAParam,
    ::testing::Values(
        std::make_tuple(std::string(""),         true),
        std::make_tuple(std::string("()"),       true),
        std::make_tuple(std::string("([{}])"),   true),
        std::make_tuple(std::string("()[]{}"),   true),
        std::make_tuple(std::string("([)]"),     false),
        std::make_tuple(std::string("("),        false),
        std::make_tuple(std::string(")"),        false),
        std::make_tuple(std::string(")("),       false),
        std::make_tuple(std::string("(()"),      false),
        std::make_tuple(std::string("())"),      false),
        std::make_tuple(std::string("]["),       false)
    )
);