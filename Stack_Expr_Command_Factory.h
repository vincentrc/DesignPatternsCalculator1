// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef STACK_EXPR_COMMAND_FACTORY_H_
#define STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
	Stack_Expr_Command_Factory (Stack <int> & stack);
	virtual ~Stack_Expr_Command_Factory ();

	//Concrete create methods for each type of command
	Num_Command * create_num_command (int num);
	Add_Command * create_add_command (void);
	Subtract_Command * create_subtract_command (void); 
	Multiply_Command * create_multiply_command (void);
	Divide_Command * create_divide_command (void);
	Modulus_Command * create_modulus_command (void);

private:
	Stack <int> & stack_;
};

#endif