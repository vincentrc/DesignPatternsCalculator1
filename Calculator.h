// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "Expr_Command.h"
#include "Stack_Expr_Command_Factory.h"
#include "Array_Iterator.h"

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.
//FIX: Created a calculator facade clas to wrap all methods


class Calculator 
{
public:

	Calculator();
	~Calculator();

	void evaluate_postfix(Array_Iterator <Expr_Command*> & iter);

	bool check_parenthesis(const std::string & infix);

	bool check_missing_operators(const std::string & infix);

	int get_precedence(std::string op);

	void append_postfix(std::string token, Stack_Expr_Command_Factory & factory, Array <Expr_Command*> &postfix, int index);

	bool infix_to_postfix(const std::string & infix, Stack_Expr_Command_Factory & factory, Array <Expr_Command*> &postfix);

};



#endif