// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command
{
protected:
	Binary_Op_Command (Stack <int> & s);

public:
	void execute (void);
	virtual int evaluate (int n1, int n2) const = 0;
		
private:
	Stack <int> & s_;
};

#endif