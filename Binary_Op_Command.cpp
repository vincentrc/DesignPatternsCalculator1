// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Binary_Op_Command.h"

//Constructor 
Binary_Op_Command::Binary_Op_Command (Stack <int> & s)
	: s_ (s)
{}

//Execute method
void Binary_Op_Command::execute (void)
{
	int n2 = this->s_.pop(), n1 = this->s_.pop();
	int result = this->evaluate(n1, n2);
	this->s_.push(result);

}