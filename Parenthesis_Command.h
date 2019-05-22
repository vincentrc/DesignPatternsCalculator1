// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Expr_Command.h"

//Command class for parnethsis (only left parenthesis since that's all that goes on the stack in the conversion)
//This class only exists to be able to put a parenthesis on the stack when converting
class Parenthesis_Command : public Expr_Command
{
public:

	Parenthesis_Command();
	int get_precedence();
	void execute (void);


};

#endif