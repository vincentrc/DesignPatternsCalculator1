// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Num_Command.h"
#include "Stack.h"

//Constructor
Num_Command::Num_Command (Stack <int> & s, int n)
	: s_ (s),
	n_ (n)
{}

//Execute command
void Num_Command::execute (void)
{
	this->s_.push(this->n_);
}
