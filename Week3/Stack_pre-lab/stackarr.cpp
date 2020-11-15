#include"stackarr.h"
#include<iostream>

using namespace std;

// Constructor

template < class DT >
Stack<DT>::Stack(int maxNumber) : maxSize(maxNumber), top(-1)
{
	element = new DT[maxSize];
}

// Destructor
template < class DT >
Stack<DT>::~Stack() {
	delete[]element;
}

// Stack manipulation operations
template < class DT >
void Stack<DT>::push(const DT& newElement) {
	if (full() == 1) {
		cout << "Stack is Full" << endl;
	}
	else {
		++top;
		element[top] = newElement;
	}
}
// Push element

template < class DT >
DT Stack<DT>::pop() {
	if (empty()) {
		cout << "Stack is Empty" << endl;
	}
	else {
		top--;
		return element[top + 1];
	}

}
// Pop element
template < class DT >
void Stack<DT>::clear() {
	top = -1;
}                    // Clear stack

// Stack status operations
template < class DT >
bool Stack<DT>::empty() const {
	if (top == -1) return 1;
	else return 0;
};                    // Stack is empty
template < class DT >
bool Stack<DT>::full() const {
	if (top == maxSize - 1) return 1;
	else return 0;
}
// Stack is full

// Output the stack structure -- used in testing/debugging
template < class DT >
void Stack<DT>::showStructure() const {
	for (int i = 0; i < top + 1; i++)
		cout << "[" << element[i] << "]";
}
//made by 2017110274 ÀÌ°­Èñ