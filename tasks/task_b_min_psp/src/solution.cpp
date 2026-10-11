#include "task_b/solution.h"
#include <unordered_map>
#include <stack>
#include <vector>

std::string BuildMinPSP(int n, const std::string& w, const std::string& s) {
    std::unordered_map<char, int>  priority;
    std::vector<char>              opens_by_priority;
    std::unordered_map<char, char> close_to_open = {
        {')', '('}, {']', '['}
    };
    std::unordered_map<char, char> open_to_close = {
        {'(', ')'}, {'[', ']'}
    };

    for (int i = 0; i < (int)w.size(); ++i) {
        priority[w[i]] = i;
        if (open_to_close.count(w[i])) opens_by_priority.push_back(w[i]);
    }

    std::stack<char> st;
    for (char ch : s) {
        auto it = close_to_open.find(ch);
        if (it != close_to_open.end()) {
            if (st.empty() || st.top() != it->second) return {}; // по условию не случится
            st.pop();
        } else {
            st.push(ch);
        }
    }

    std::string result = s;
    for (int i = (int)s.size(); i < n; ++i) {
        for (char ch : w) {
            auto it = close_to_open.find(ch);
            if (it != close_to_open.end()) {
                if (!st.empty() && st.top() == it->second) {
                    st.pop();
                    result += ch;
                    break;
                }
            } else {
                // Проверяем, что хватит места закрыть все открытые + эту
                if ((int)st.size() + 1 <= n - i) {
                    st.push(ch);
                    result += ch;
                    break;
                }
            }
        }
    }
    return result;
}