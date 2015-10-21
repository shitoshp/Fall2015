#include "Stack.h"
#include <iostream>
using namespace std;


template <class A>
StackType<A>::StackType()
{
	top = -1;
}

template <class A>
bool StackType<A>::IsEmpty() const
{
	return (top == -1);
}


template <class A>
bool StackType<A>::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}

template <class A>

void StackType<A>::Push(A my_item)
{
	if (IsFull())
		cout << "Stack is full" << endl;
	else
		top++;
		items[top] = my_item;
}

template <class A> 
void StackType<A>::Pop()
{
	if (IsEmpty())
		cout << "Stack is empty" << endl;
	else
		top--;
}

template <class A>
int StackType<A>::Topindex()
{
	return top;
}

template <class A>
A StackType<A>::Top()
{
	if (IsEmpty())
		cout << "Stack is empty" << endl;
	else
		return items[top];
}