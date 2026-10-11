#include "task_b/solution.h"
#include <iostream>
#include <string>

int main() {
    int n;
    std::string w, s;
    std::cin >> n >> w >> s;
    std::cout << BuildMinPSP(n, w, s) << std::endl;
    return 0;
}