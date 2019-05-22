// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack_Expr_Command_Factory.h"

//Initializing Constructor
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int> & stack)
	:stack_ (stack)
{}

//Destructor
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory ()
{}

//Create num command
Num_Command * Stack_Expr_Command_Factory::create_num_command (int num)
{
	//Create a new num command ptr
	return new Num_Command(this->stack_, num);
}

//Create add command
Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
	//Create a new num command ptr
	return new Add_Command(this->stack_);
}

//Create subtract command
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
	//Create a new num command ptr
	return new Subtract_Command(this->stack_);
}

//Create multiply command
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
	//Create a new num command ptr
	return new Multiply_Command(this->stack_);
}

//Create divide command
Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
	//Create a new num command ptr
	return new Divide_Command(this->stack_);
}

//Create modulus command
Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
	//Create a new num command ptr
	return new Modulus_Command(this->stack_);
}
