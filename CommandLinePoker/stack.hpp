//Defintion for stack discussed in class


#ifndef CS2_STACK_HPP
#define CS2_STACK_HPP


#include <cassert>

const int SIZE = 52;

template <typename T>
class stack {
public:
	stack() : tos(-1) {};
	bool	isEmpty()				const { return tos == -1; };
	bool	isFull()				const { return tos >= SIZE - 1; };
	void	push(const T& item) { assert(!isFull());  s[++tos] = item; };
	T		pop() { assert(!isEmpty()); return s[tos--]; };
	T		top()				const { assert(!isEmpty()); return s[tos]; };

private:
	int tos;
	T	s[SIZE];
};

#endif