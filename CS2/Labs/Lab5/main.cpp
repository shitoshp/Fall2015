#include <iostream>
#include "Stack.cpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


int main(){

	srand (time(NULL));
	int num, temp;
	

	StackType <int> stack1;
	StackType <int> stack2;
	StackType <int> stack3;
/*
	int compare[20];
	int index = 0;
	int stacklist[20];
	int stackindex = 0;
*/
	for (int i = 0; i < 5; i++) {
		num = rand() % 50 + 1;
		stack1.Push(num);
		cout << num << " ";
		
	}

	
	
	
	
	cout << endl; 
	

	

	int x = stack1.Top();
	cout << x << endl;

	//number 2
	
	while (!stack1.IsEmpty()) {
		stack2.Push(stack1.Top());
		stack1.Pop();
		
	}
	cout << endl;

	while (!stack2.IsEmpty()) {
		cout << stack2.Top()<< " ";
		stack1.Push(stack2.Top());
		stack2.Pop();
	}

	cout << endl;

	
	//number 3 sorting
	while (!stack1.IsEmpty()) {
		temp = stack1.Top();
		stack1.Pop();
		while (!stack3.IsEmpty() && temp > stack3.Top()) {
			stack1.Push(stack3.Top());
			stack3.Pop();
		}
		stack3.Push(temp);
	}

	

	while (!stack3.IsEmpty()) {
		cout << stack3.Top() << " ";
		stack3.Pop();
	}

	system("pause"); // Only necessary if using Visual Studio
	return 0;

	system("pause"); // Only necessary if using Visual Studio
	return 0;

return 0;
}

