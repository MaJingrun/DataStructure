#pragma once
#include<ostream>

template<class T>
class ChainNode {
	template<class T>
	friend class Chain;
private:
	T data;
	ChainNode<T> *link;
};

template<class T>
class Chain {
public:
	Chain() { first = 0; }
	~Chain();
	bool IsEmpty()const { return first == 0; }
	int Length()const;
	bool Find(int k, T&x)const;
	int Search(const T&x)const;
	Chain<T>& Delete(int k, T&x);
	Chain<T>& Insert(int k, const T&x);
	void Output(std::ostream& out)const;
	void BinSort(int range);
private:
	ChainNode<T> *first;
};



template<class T>
inline Chain<T>::~Chain()
{
	ChainNode<T> *next;
	while (first) {
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
inline int Chain<T>::Length() const
{
	ChainNode<T> *p = first;
	int len = 0;
	while (p) {
		len++;
		p = (*p).link;
	}
	return len;
}

template<class T>
inline bool Chain<T>::Find(int k, T & x) const
{
	if (k<1)return false;
	ChainNode<T>* p = first;
	int index = 1;
	while (index < k && p) {
		p = p->link;
		index++;
	}
	if (p) {
		x = p->data;
		return true;
	}
	return false;
}

template<class T>
inline int Chain<T>::Search(const T & x) const
{
	ChainNode<T> *p = first;
	int index = 1;
	while (p&&p->data != x) {
		index++;
		p = p->link;
	}
	if (p)return index;
	return 0;
}

template<class T>
inline Chain<T>& Chain<T>::Delete(int k, T & x)
{
	/*if (k < 1 || !first) {}
	ChainNode<T> *p = first;
	if (k == 1) {
	first = first->link;
	}
	else {
	ChainNode<T> *q = first;
	int index = 1;
	while (index < k&&p) {
	index++;
	q = p;
	p = p->link;
	}
	q->link = p->link;
	}
	delete p;
	return *this;*/
	if (k < 1 || !first) {}
	ChainNode<T> *p = first;
	if (k == 1) {
		first = first->link;
	}
	else {
		ChainNode<T> *q = first;
		for (int index = 1;index < k - 1 && q;index++)
			q = q->link;
		if (!q || !q->link) {}
		p = q->link;
		q->link = p->link;
	}
	x = p->data;
	delete p;
	return *this;

}

template<class T>
inline Chain<T>& Chain<T>::Insert(int k, const T & x)
{
	if (k<0) {}
	ChainNode<T> *y = new ChainNode<T>();
	y->data = x;
	if (k == 0 && !first) {
		first = y;
		y = 0;
	}
	else {
		int index = 1;
		ChainNode<T> *p = first;
		while (index < k&&p) {
			index++;
			p = p->link;
		}
		if (p) {
			y->link = p->link;
			p->link = y;
		}
		else {
			std::cout << "����λ�ô���" << endl;
		}

	}
	return *this;


}

template<class T>
inline void Chain<T>::Output(std::ostream & out) const
{
	ChainNode<T> *p = first;
	while (p) {
		out << p->data << " ";
		p = p->link;
	}
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}

template<class T>
void Chain<T>::BinSort(int range) {
	int b;
	ChainNode<T> **bottom, **top;
	bottom = new ChainNode<T>*[range + 1];
	top = new ChainNode<T>*[range + 1];
	for (b = 0;b <= range;b++) {
		bottom[b] = 0;
	}
	for (;first;first = first->link) {
		b = first->data;
		if (bottom[b]) {
			top[b]->link = first;
			top[b] = first;
		}
		else
			bottom[b] = top[b] = first;
	}
	ChainNode<T>*y = 0;
	for (b = 0;b <= range;b++)
		if (bottom[b]) {
			if (y)
				y->link = bottom[b];
			else
				first = bottom[b];
			y = top[b];
		}
	if (y)y->link = 0;
	delete[]bottom;
	delete[]top;
}