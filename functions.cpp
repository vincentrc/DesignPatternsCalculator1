// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "functions.h"
#include "Array.h"
#include "Expr_Command.h"
#include "Stack_Expr_Command_Factory.h"

//Function to evaluate a postfix command array
void evaluate_postfix(Array_Iterator <Expr_Command*> & iter)
{
	//Iterate through
	for(;!iter.is_done();iter.advance())
	{
		(*iter)->execute();
	}
}

//Checks to make sure parenthesis structure is correct
bool check_parenthesis(const std::string & infix)
{
	std::istringstream input(infix);	//Create an input stream parser
	std::string token;					//Current token in string stream
	Stack <std::string> temp;			//Stack for storing parenthesis


	while(!input.eof())
	{
		input >> token;

		//Push all "("
		if (token == "(")
			temp.push(token);

		//For ")", check for matching "("
		else if (token == ")")
		{
			//If no parenthesis in stack, then must be invalid
			if (temp.is_empty())
				return false;
			//If there are, pop one to match the current ")"
			else
				temp.pop();
		}
	}

	//If the stack is empty, all parenthesis have a match, otherwise there was some error
	if (temp.is_empty())
		return true;
	else
		return false;
}

//Checks to make sure there a no missing operators (two nums in a row: "4 4 - 6 + 8" for example) or two+ operators in a row
bool check_missing_operators(const std::string & infix)
{
	int prevop = -1;					//Variable to tell if prev token was an operator/parenthesis: 3 = left parenthesis 2 = right parenthesis 1 = operator 0 = operand
	std::istringstream input(infix);	//Create an input stream parser
	std::string token;					//Current token in string stream
	Stack <std::string> temp;			//Stack for storing parenthesis
	int numcount = 0, opcount = 0;		//Counts to make sure at least 2 numbers/operands and 1 operator
	int first = 1;

	while(!input.eof())
	{
		input >> token;

		//If token is an operator
		if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
		{
			//First token is operator
			if (first == 1)
				return false;

			//Two operators in a row or last token was left parenthesis
			if (prevop == 1 || prevop == 3)
				return false;

			prevop = 1;
			opcount++;
		}

		//If token is a left parenthesis
		else if (token == "(")
		{
			//Check if last token was an operand
			if (prevop == 0)
				return false;

			prevop = 3;
		}

		//If token is a right parenthesis
		else if  (token == ")")
		{
			//Check if last token was an operand
			if (prevop == 1)
				return false;

			prevop = 2;
		}

		//Otherwise assume it's an operand/number (not a number error handling is in conversion formula)
		else
		{
			//Missing operator
			if (prevop == 0)
				return false;

			prevop = 0;
			numcount++;
		}

		first = 0;
	}

	//Check operator and operand counters and make sure last token wasn't operator
	if (numcount < 2 || opcount < 1 || prevop == 1)
		return false;

	return true;
}

//Function to convert an infix expression string to a postfix array of expression commands
bool infix_to_postfix(const std::string & infix, Stack_Expr_Command_Factory & factory, Array <Expr_Command*> &postfix)
{
	std::istringstream input(infix);	//Create an input stream parser
	std::string token;					//Current token in string stream
	Expr_Command * cmd = 0;				//Command object ptr
	Stack <Expr_Command *> temp;		//Stack for conversion algorithm
	int index=0;						//Keeps track of number of expressions
	int num, x;
	Expr_Command *cmdtemp = 0;

	//Make sure the postfix array is large enough (excess elements will be removed at the end)
	postfix.resize(infix.size());

	//Loop to iterate through the infix stream one token at a time
	while(!input.eof())
	{
		input >> token;

		//Create command based on token using factory
		if (token == "+")
			cmd = factory.create_add_command();

		else if (token == "-")
			cmd = factory.create_subtract_command();

		else if (token == "*")
			cmd = factory.create_multiply_command();

		else if (token == "/")
			cmd = factory.create_divide_command();

		else if (token == "%")
			cmd = factory.create_modulus_command();

		else if (token == "(")
			cmd = factory.create_parenthesis_command();

		else if (token == ")")
			cmd = 0;

		//Check if the expression is a number, if not invalid
		else
		{
			try	//Try converting the token to an integer
			{
				num = stoi(token);
			}
			//If an exception was thrown, either wasn't a num or out of range
			catch (std::exception& e)
			{
				std::cout << e.what() << " failed, not an integer." << "\n\n";
				return false;
			}

			//If successful, create a num command and proceed accordingly
			cmd = factory.create_num_command(num);
		}

		//Conversion Algorithm

		//If right parenthesis 
		if (cmd == 0)
		{

			//Pop off stack until matching open parenthesis found
			while(1)
			{
				//Check for invalid expression structure
				if (temp.is_empty())
					return false;

				cmdtemp = temp.pop();
				
				//If matching parenthesis found
				if (cmdtemp->get_precedence() == 3)
					break;

				//Insert the command into the postfix expression
				postfix[index] = cmdtemp;
				index++;

			}

			//Delete the left parethesis object
			delete cmdtemp;
		}

		//If command is a num command
		else if (cmd->get_precedence() == 0)
		{
			postfix[index] = cmd;
			index++;
		}

		//If command is an operator or left parenthesis
		else
		{
			//Iterate until cmd is highest precedence
			while(1)
			{
				//If stack is empty
				if (temp.is_empty())
				{
					temp.push(cmd);
					break;
				}

				//If cmd is higher precedence than top
				if (temp.top()->get_precedence() < cmd->get_precedence() || temp.top()->get_precedence() == 3)
				{
					temp.push(cmd);
					break;
				}

				//Pop top off stack and add to postfix expression
				cmdtemp = temp.pop();
				postfix[index] = cmdtemp;
				index++;
			}

			
		}

	}

	//Finish conversion by popping off of stack until empty
	while(!temp.is_empty())
	{
		cmdtemp = temp.pop();
		postfix[index] = cmdtemp;
		index++;
	}

	//If the conversion was successful, resize postfix to proper size and return 
	postfix.resize(index);
	return true;

}