// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 2, 2023
// Last Update: May 2, 2023
// Problem statement: N Dim Vector

#pragma once

#include <iostream>
#include <vector>

class VecNf
{
private:
	std::vector<float> _data;

public:
	VecNf() : _data({ 0.0f }) { }

	VecNf(float* dest, int cnt)
	{
		for (int i = 0; i < cnt; i++)
			_data.push_back(dest[i]);
	}

	VecNf(const VecNf& rhs) { this->_data = rhs._data; }

	inline int Size() const { return this->_data.size(); }

	inline VecNf& operator=(const VecNf& v)
	{
		std::cout << "ASSIGNMENT!!!" << std::endl;
		_data = v._data;
		return *this;
	}

	inline float& operator[](int index) { return this->_data[index]; }

	friend VecNf operator+(const VecNf& v1, const VecNf& v2)
	{
		VecNf result;
		if (v1.Size() != v2.Size())
		{
			std::cout << "dimensions inconsistent" << std::endl;
			return result;
		}
		int size = v1.Size();
		result._data[0] = v1._data[0] + v2._data[0];
		for (int i = 1; i < size; i++)
			result._data.push_back(v1._data[i] + v2._data[i]);
		return result;
	}

	friend VecNf operator-(const VecNf& v1, const VecNf& v2)
	{
		VecNf result;
		if (v1.Size() != v2.Size())
		{
			std::cout << "dimensions inconsistent" << std::endl;
			return result;
		}
		int size = v1.Size();
		result._data[0] = v1._data[0] - v2._data[0];
		for (int i = 1; i < size; i++)
			result._data.push_back(v1._data[i] - v2._data[i]);
		return result;
	}

	friend float operator*(const VecNf& v1, const VecNf& v2)
	{
		float result(0);
		if (v1.Size() != v2.Size())
		{
			std::cout << "dimensions inconsistent" << std::endl;
			return result;
		}
		int size = v1.Size();
		for (int i = 0; i < size; i++)
			result += v1._data[i] * v2._data[i];
		return result;
	}

	friend VecNf operator*(const VecNf& v1, float n)
	{
		VecNf newVec;
		newVec._data.clear();
		for (const auto& f : v1._data)
			newVec._data.push_back(f * n);
		return newVec;
	}

	friend VecNf operator*(float n, const VecNf& v1)
	{
		VecNf newVec;
		newVec._data.clear();
		for (const auto& f : v1._data)
			newVec._data.push_back(f * n);
		return newVec;
	}
};