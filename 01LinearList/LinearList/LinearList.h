#pragma once
#include<ostream>

using namespace std;

template<class T>
class LinearList
{
public:
	LinearList(int MaxListSize = 10);
	~LinearList();
	bool isEmplty() const { return length == 0; }
	int Length() const { return length; }
	bool Find(int k, T&x) const;
	int Search(const T&x) const;
	LinearList<T>& Delete(int k, T&x);
	LinearList<T>& Insert(int k, const T&x);
	void Output(ostream& out) const;

protected:

private:
	int length;
	int MaxSize;
	T *element;
};





template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

template<class T>
LinearList<T>::~LinearList()
{
	delete[] element;
}

template<class T>
bool LinearList<T>::Find(int k, T&x) const
{
	if (k<1 || k>length)return false;
	x = element[k - 1];
	return true;
}

template<class T>
int LinearList<T>::Search(const T&x)const
{
	for (int i = 0; i<length; i++)
	{
		if (element[i] == x)return ++i;
	}
	return 0;
}

template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T&x)
{
	if (Find(k, x))
	{
		for (int i = k; i<length; i++)
		{
			element[i - 1] = element[i];
		}
		length--;
		return *this;
	}
	else std::cout << "越界" << std::endl;//throw OutOfBounds();
}

template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T&x)
{
	if (k<0 || k>length)std::cout << "k在范围之外" << std::endl;//throw OutOfBounds();
	if (length == MaxSize)std::cout << "已满" << std::endl; //throw NoMem();
	for (int i = length - 1; i >= k; i--)
	{
		element[i + 1] = element[i];
	}
	element[k] = x;
	length++;
	return *this;
}

template<class T>
void LinearList<T>::Output(ostream &out)const
{
	for (int i = 0; i<length; i++)
	{
		out << element[i] << " ";
	}
}

template<class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out);
	return out;
}