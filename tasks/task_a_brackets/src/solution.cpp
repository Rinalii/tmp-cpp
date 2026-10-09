#include "task_a/solution.h"
#include <iostream>
#include <stack>
#include <unordered_map>

bool IsCorrectBracketSequence(const std::string& str) {
    static const std::unordered_map<char, char> brackets = {
        {'}', '{'},
        {']', '['},
        {')', '('}
    };

    std::stack<char> curr_open;

    for (char ch : str) {
        auto it = brackets.find(ch);
        if (it != brackets.end()) {          // закрывающая скобка
            if (curr_open.empty() || curr_open.top() != it->second) {
                return false;
            }
            curr_open.pop();
        } else {                              // открывающая скобка
            curr_open.push(ch);
        }
    }

    return curr_open.empty();
}