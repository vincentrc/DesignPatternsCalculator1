// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

//Command class for performing addition
class Num_Command : public Expr_Command
{
public:

	Num_Command (Stack <int> & s, int n);
	void execute (void);

private:
	Stack <int> & s_;
	int n_;
  
  // COMMENT Numbers do not have a precedence.
	//FIX: Removed it in favor of new implementation
};

#endif