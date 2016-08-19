#pragma once
#include<ostream>
#include<excpt.h>
#include<iostream>

template<class T>
class IndirectList {
public:
	IndirectList(int MaxListSize = 10);
	~IndirectList();
	bool IsEmpty()const { return length == 0; }
	int Length()const { return length; }
	bool Find(int k, T&x)const;
	int Search(const T&x)const;
	IndirectList<T>& Delete(int k, T&x);
	IndirectList<T>& Insert(int k, const T&x);
	void Output(std::ostream& out)const;
private:
	T **table;
	int length, MaxSize;
};


template<class T>
inline IndirectList<T>::IndirectList(int MaxListSize)
{
	MaxSize = MaxListSize;
	table = new T *[MaxSize];
	length = 0;
}

template<class T>
inline IndirectList<T>::~IndirectList()
{
	for (int i = 0;i < length;i++) {
		delete table[i];
	}
	delete [] table;
}

template<class T>
inline bool IndirectList<T>::Find(int k, T & x) const
{
	if (k<1 || k>length)return false;
	x = *table[k - 1];
	return true;
}

template<class T>
inline int IndirectList<T>::Search(const T & x) const
{
	for (int i = 0;i < length;i++)
		if (*table[i] == x)return ++i;
	return 0;
}

template<class T>
inline IndirectList<T>& IndirectList<T>::Delete(int k, T & x)
{
	if (Find(k, x)) {
		for (int i = k;i < length;i++)
			table[i - 1] = table[i];
		length--;
		return *this;
	}
	else throw OutOfBounds();
}

template<class T>
inline IndirectList<T>& IndirectList<T>::Insert(int k, const T & x)
{
	if (k<0 || k>length)throw OutOfBounds();
	if (length == MaxSize)throw NoMem();

	for (int i = length - 1;i >= k;i++)
		table[i + 1] = table[i];
	table[k] = new T;
	*table[k] = x;
	length++;
	return *this;
	// TODO: 在此处插入 return 语句
}

template<class T>
inline void IndirectList<T>::Output(std::ostream & out) const
{
	for (int i = 0;i < length;i++) {
		out << *table[i] << " ";
	}
}
template<class T>
std::ostream& operator<<(std::ostream& out, const IndirectList<T>& x) {
	x.Output(out);
	return out;
}


class OutOfBounds{
public:
	OutOfBounds() { std::cout << "yuejie"; }
};
class NoMem{
public:
	NoMem(){}
};