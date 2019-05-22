// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include <iostream>

#define defaultSize 0

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
	: stackarray (Array <T> (defaultSize))
{}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	: stackarray (stack.stackarray) //Uses copy constructor of array class to copy other stack
{}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{}	//Nothing declared on heap

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	//Increment the stack pointer, resize and add the new element
	//if (this->stackarray.size() > 0)
		//std::cout << "\n\n" << stackarray[this->stackarray.size()-1] << "\n\n";
	this->stackarray.resize(this->stackarray.size()+1);
	//if (this->stackarray.size() > 1)
		//std::cout << "\n\n" << stackarray[this->stackarray.size()-2] << "\n\n";
	this->stackarray[this->stackarray.size()-1] = element;

}

//
// pop
//
template <typename T>
T Stack <T>::pop (void)
{
	T temp = this->top();

	//First check if the stack is empty
	if (this->is_empty())
		throw Stack::empty_exception("The stack is empty!");

	//Remove the top element and resize the stack
	this->stackarray.resize(this->stackarray.size()-1);
	return temp;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	// COMMENT Check for self assignment.
	//FIX: Checked for self assignment by comparing the attributes
	if (this->stackarray == rhs.stackarray)
		return *this;
  
	//Set the variables equal to those of the rhs
	this->stackarray = rhs.stackarray;

	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	//Resize the stack to 0 and reset the stack pointer
	this->stackarray.resize(0);
}
