#pragma once
#include <iostream>

template <typename T>
class TArray final
{
	template <typename T>
	friend std::ostream& operator << (std::ostream& os, const TArray<T>& tarray);
public:
	TArray(size_t _size = 0);
	~TArray();
	void setValue(size_t index, T value);
private:
	size_t m_size;
	T* m_array;
};

template <typename T>
TArray<T>::TArray(size_t _size)
	: m_size{ _size }
{
	if (_size > 0) {
		m_array = new T[_size];
	}
	else {
		m_array = nullptr;
	}
}

template <typename T>
TArray<T>::~TArray()
{
	delete[] m_array;
	//m_array = nullptr;
	//m_size = 0;
}

template <typename T>
void TArray<T>::setValue(size_t index, T value)
{
	m_array[index] = value;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const TArray<T>& tarray)
{
	os << "TArray size " << tarray.m_size << "\n";
	if (tarray.m_size > 0) {
		for (size_t index = 0; index < tarray.m_size; ++index) {
			os << "  [" << index << "] = " << tarray.m_array[index] << "\n";
		}
	}
	return os;
}