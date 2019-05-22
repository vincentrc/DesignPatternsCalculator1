// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Parenthesis_Command.h"


//Constructor
Parenthesis_Command::Parenthesis_Command()
	: Expr_Command ()
{
	this->precedence = 3;
}

//Shouldn't be called
void Parenthesis_Command::execute(void)
{
	return;
}

//Returns precedence value
int Parenthesis_Command::get_precedence()
{
	return this->precedence;
}