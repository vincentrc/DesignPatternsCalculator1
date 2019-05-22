// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include <iostream>
#include <string>
#include "Array_Iterator.h"
#include "Calculator.h"

int main(int argc, char * argv[])
{
	Array <Expr_Command*> a1 = Array <Expr_Command*> ();
	Stack <int> s1 = Stack <int> ();
	Stack_Expr_Command_Factory f1 (s1);
	std::string expression;
	Calculator *Calc = new Calculator();

	//Main program loop
	while(1)
	{

		//Take in a line from stdin
		std::getline(std::cin, expression);

		//Quit the program when the user enters QUIT
		if (expression == "QUIT")
		{
			delete Calc;
			return 0;
		}

		//Create array iterators
		Array_Iterator <Expr_Command*> i1 = Array_Iterator <Expr_Command*> (a1);
		Array_Iterator <Expr_Command*> i2 = Array_Iterator <Expr_Command*> (a1);

		//Check the expression for validity
		if (!Calc->check_parenthesis(expression))	//Parenthesis structure check
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		if (!Calc->check_missing_operators(expression)) //Missing or back-to-back operators check
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		//Run conversion algorithm and check for errors
		if (!Calc->infix_to_postfix(expression, f1, a1))
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		//If conversion was successful, evaluate the expression and print results to stdout
		Calc->evaluate_postfix(i1);

		//In case s1 is somehow empty
		if (s1.is_empty())
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		std::cout << "\n\nThe answer is: " << s1.pop() << "\n\n";

		//Free the memory and clear the stack for the next expression
		for(;!i2.is_done();i2.advance())
		{
			delete (*i2);
		}

		s1.clear();

	}
}
