// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Modulus_Command.h"
#include "Binary_Op_Command.h"
#include "Stack.h"

//Constructor
Modulus_Command::Modulus_Command(Stack <int> & s)
	: Binary_Op_Command (s)
{}


//Addition command
int Modulus_Command::evaluate (int n1, int n2) const
{
	return n1 % n2;
}
