/*
 * ExpressionManager.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_EXPRESSIONMANAGER_H_
#define TO_STUDENTS_STUDENT_CODE_EXPRESSIONMANAGER_H_

#include "ExpressionManagerInterface.h"
#include <stack>
#include <sstream>
#include <cctype>

namespace std {

class ExpressionManager: public ExpressionManagerInterface {
public:
	ExpressionManager();
	virtual ~ExpressionManager();

	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

	char parentheticalOppositeOf(char parentheticalCharacter);

	void clearStack(stack<char> &s);
	void clearStack(stack<string> &s);
	void printStack(stack<char> s);
	void printStack(stack<string> s);
	bool expressionIsValid(string expression);
	bool characterIsParenthesis(char character);
	bool characterIsLeftParenthesis(char character);
	bool characterIsRightParenthesis(char character);
	bool stringIsOperator(string token);
	bool characterIsOperator(char character);

	bool operatorIsLeftAssociative(char op);
	bool operatorIsRightAssociative(char op);

	bool tokenIsInteger(string token);

	int getPrecedentScore(char op);

	string evaluateSubExpression(int int1, int int2, char op);

private:
	stack<char> operatorStack;
	stack<char> parenthesisStack;
	stack<string> operandStack;
};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_EXPRESSIONMANAGER_H_ */
