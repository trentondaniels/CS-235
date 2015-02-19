#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;


class ExpressionManagerInterface
{
	public:
		ExpressionManagerInterface(){}
		virtual ~ExpressionManagerInterface(){}

	/*
	* Checks whether an expression is balanced on its parentheses
	* 
	* - The given expression will have a space between every number or operator
	* 
	* @return true if expression is balanced
	* @return false otherwise
	*/

virtual bool isBalanced(string expression) = 0;

	/**
	 * Converts a postfix expression into an infix expression
	 * and returns the infix expression.
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - The returned infix expression must have a space between every number or operator.
	 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix expression.
	 * otherwise, return the correct infix expression as a string.
	 */
virtual string postfixToInfix(string postfixExpression) = 0;
	
	/*
	 * Converts an infix expression into a postfix expression 
	 * and returns the postfix expression
	 * 
	 * - The given infix expression will have a space between every number or operator.
	 * - The returned postfix expression must have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 * 
	 * return the string "invalid" if infixExpression is not a valid infix expression.
	 * otherwise, return the correct postfix expression as a string.
	 */
virtual string infixToPostfix(string infixExpression) = 0;
	
	/*
	 * Evaluates a postfix expression returns the result as a string
	 * 
	 * - The given postfix expression will have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 * 
	 * return the string "invalid" if postfixExpression is not a valid postfix Expression
	 * otherwise, return the correct evaluation as a string
	 */
virtual string postfixEvaluate(string postfixExpression) = 0;


};