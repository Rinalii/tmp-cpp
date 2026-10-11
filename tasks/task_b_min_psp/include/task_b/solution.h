#pragma once
#include <string>

// Возвращает лексикографически минимальную ПСП длины n,
// начинающуюся со строки s, при порядке скобок w.
// Гарантируется, что ответ существует.
std::string BuildMinPSP(int n, const std::string& w, const std::string& s);