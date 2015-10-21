#pragma once
#define MAX_ITEMS 101
template <class A> class StackType
{

	//const int MAX_ITEMS;
public:
	StackType();

	bool IsFull() const;

	bool IsEmpty() const;

	void Push(A item);

	void Pop();

	A Top();

	int Topindex();

private:
	
	int top;
	
	A items[MAX_ITEMS];

	
};