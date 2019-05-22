// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Divide_Command.h"
#include "Binary_Op_Command.h"
#include "Stack.h"

//Constructor
Divide_Command::Divide_Command(Stack <int> & s)
	: Binary_Op_Command (s)
{}


//Addition command
int Divide_Command::evaluate (int n1, int n2) const
{
	return n1 / n2;
}
