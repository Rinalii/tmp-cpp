#include "task_a/solution.h"
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    std::cout << (IsCorrectBracketSequence(str) ? "yes" : "no") << std::endl;
    return 0;
}