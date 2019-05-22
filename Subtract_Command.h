// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

//Command class for performing addition
class Subtract_Command : public Binary_Op_Command
{
public:

	Subtract_Command(Stack <int> & s);
	int evaluate (int n1, int n2) const;

  // COMMENT Since this variable is common to all operators, you should
  // move it to the base class.
	//FIX: Removed it in favor of new implementation
};

#endif