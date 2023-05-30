// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 31, 2023
// Last Update: May 31, 2023
// Problem statement: AbsoluteValue

#pragma once

#include <cmath>

template <typename T>
inline double absoluteValue(T a, T b)
{
	T sub = a - b;
	return std::abs(sub);
}