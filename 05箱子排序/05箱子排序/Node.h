#pragma once
#include<ostream>

class Node {
	friend std::ostream& operator<<(std::ostream&, const Node&);
public:
	int operator!=(Node x)const {
		return (score != x.score);
	}
	operator int()const { return score; }
private:
	int score;
	char *name;
};

std::ostream&operator<<(std::ostream& out, const Node& x) {
	out << x.score << " ";
	return out;
}