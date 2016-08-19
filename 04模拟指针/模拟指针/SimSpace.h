#pragma once

template<class T>
class SimNode {
	template<class T>
	friend class SimSpace;
private:
	T data;
	int link;
};

template<class T>
class SimSpace {
public:
	SimSpace(int MaxSpaceSize = 100);
	~SimSpace()
	{
		delete[] node;
	}
	int Allocate();
	void Deallocate(int &i);
private:
	int NumberOfNodes, first;
	SimNode<T> *node;
};

template<class T>
inline SimSpace<T>::SimSpace(int MaxSpaceSize)
{
	NumberOfNodes = MaxSpaceSize;
	node = new SimNode<T>[NumberOfNodes];
	for (int i = 0;i < NumberOfNodes;i++)
		node[i].link = i + 1;
	node[NumberOfNodes - 1].link = -1;
	first = 0;
}

template<class T>
inline int SimSpace<T>::Allocate()
{
	if (first == -1)throw NoMem();
	int i = first;
	first = node[i].link;
	return i;
}

template<class T>
inline void SimSpace<T>::Deallocate(int & i)
{
	node[i].link = first;
	first = i;
	i = -1;
}



class NoMem {

};