/*
 * ExpressionManager.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Jason
 */

#include "ExpressionManager.h"

namespace std {

ExpressionManager::ExpressionManager() {
	clearStack(operatorStack);
	clearStack(parenthesisStack);
	clearStack(operandStack);
}

ExpressionManager::~ExpressionManager() {
	// TODO Auto-generated destructor stub
}

void ExpressionManager::clearStack(stack<char> &s) {
	while (!s.empty()) {
		s.pop();
	}
}

void ExpressionManager::clearStack(stack<string> &s) {
	while (!s.empty()) {
		s.pop();
	}
}

void ExpressionManager::printStack(stack<char> s) {
	stack<char> temp = s;
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << flush;
}

void ExpressionManager::printStack(stack<string> s) {
	stack<string> temp = s;
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << flush;
}

bool ExpressionManager::operatorIsLeftAssociative(char op) {
	if (op == '+' || op == '-') {
		return true;
	} else if (op == '*' || op == '/' || op == '%') {
		return false;
	} else {
		return true;
	}
}

bool ExpressionManager::operatorIsRightAssociative(char op) {
	if (op == '+' || op == '-') {
		return false;
	} else if (op == '*' || op == '/' || op == '%') {
		return true;
	} else {
		return false;
	}
}

char ExpressionManager::parentheticalOppositeOf(char parentheticalCharacter) {
	switch (parentheticalCharacter) {
	case '(':
		return ')';
		break;
	case ')':
		return '(';
		break;
	case '[':
		return ']';
		break;
	case ']':
		return '[';
		break;
	case '{':
		return '}';
		break;
	case '}':
		return '{';
		break;
	default:
		return char();
		break;
	}
}

bool ExpressionManager::characterIsLeftParenthesis(char character) {
	if (character == '(' || character == '[' || character == '{') {
		return true;
	} else {
		return false;
	}
}

bool ExpressionManager::characterIsRightParenthesis(char character) {
	if (character == ')' || character == ']' || character == '}') {
		return true;
	} else {
		return false;
	}
}

bool ExpressionManager::isBalanced(string expression) {
	clearStack(parenthesisStack);
	stringstream ss;
	ss << expression;
	char character = char();

	while (ss >> character) {
		if (character == '(' || character == '[' || character == '{') {
			parenthesisStack.push(character);
		} else if (character == ')' || character == ']' || character == '}') {
			if (!parenthesisStack.empty()) {
				if (parenthesisStack.top()
						== parentheticalOppositeOf(character)) {
					parenthesisStack.pop();
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
	}
	if (parenthesisStack.empty()) {
		return true;
	}
	return false;

}

bool ExpressionManager::characterIsParenthesis(char character) {
	if (character == '(' || character == '[' || character == '{'
			|| character == ')' || character == ']' || character == '}') {
		return true;
	} else {
		return false;
	}
}

bool ExpressionManager::stringIsOperator(string token) {
	token = token[0];
	if (token == "+" || token == "-" || token == "*" || token == "/"
			|| token == "%") {
		return true;
	} else {
		return false;
	}
}

bool ExpressionManager::characterIsOperator(char character) {

	if (character == '+' || character == '-' || character == '*'
			|| character == '/' || character == '%') {
		return true;
	} else {
		return false;
	}
}

int ExpressionManager::getPrecedentScore(char op) {
	if (op == '+' || op == '-') {
		return 4;
	} else if (op == '*' || op == '/' || op == '%') {
		return 3;
	} else {
		return 2;
	}
}

bool ExpressionManager::tokenIsInteger(string token) {
	string tokenCopy = token;
	int testInt;
	double testDouble;
	stringstream ss1, ss2;
	ss1 << token;
	ss2 << tokenCopy;

	ss1 >> testInt;
	ss2 >> testDouble;

	return testInt == testDouble;
}

bool ExpressionManager::expressionIsValid(string expression) {
	if (!isBalanced(expression)) {
		return false;
	}
	stringstream ss;
	ss << expression;
	int operators = 0, numbers = 0;
	string token;

	while (ss >> token) {
		if (stringIsOperator(token)) {
			operators++;
		} else if (isdigit(token[0])) {
			numbers++;
		} else if (!characterIsParenthesis(token[0])
				|| !tokenIsInteger(token)) {
			return false;
		}
	}
	if (numbers == operators + 1) {
		return true;
	} else {
		return false;
	}
}

string ExpressionManager::evaluateSubExpression(int int1, int int2, char op) {
	stringstream converter;
	string resultString;
	int resultInt;
	switch (op) {
	case '+':
		resultInt = int2 + int1;
		converter << resultInt;
		converter >> resultString;
		return resultString;
		break;
	case '-':
		resultInt = int2 - int1;
		converter << resultInt;
		converter >> resultString;
		return resultString;
		break;
	case '*':
		resultInt = int2 * int1;
		converter << resultInt;
		converter >> resultString;
		return resultString;
		break;
	case '/':
		if (int1 == 0) {
			return "invalid";
		}
		resultInt = int2 / int1;
		converter << resultInt;
		converter >> resultString;
		return resultString;
		break;
	case '%':
		resultInt = int2 % int1;
		converter << resultInt;
		converter >> resultString;
		return resultString;
		break;
	}
}
string ExpressionManager::postfixToInfix(string postfixExpression) {
	if (!expressionIsValid(postfixExpression)) {
		return "invalid";
	}
	clearStack(operatorStack);
	clearStack(operandStack);

	string output, subExpression;
	string tokenFromStack1, tokenFromStack2;
	string token;
	stringstream ss;
	ss << postfixExpression;

	while (ss >> token) {
		if (output != "") {
			output += " ";
		}
		if (isdigit(token[0])) {
			if (tokenIsInteger(token)) {
				operandStack.push(token);
			} else {
				return "invalid";
			}

		} else if (characterIsOperator(token[0])) {
			if (operandStack.empty() || !tokenIsInteger(operandStack.top())
					|| operandStack.size() < 2) {
				return "invalid";
			}
			tokenFromStack1 = operandStack.top();
			operandStack.pop();
			tokenFromStack2 = operandStack.top();
			operandStack.pop();

			subExpression = "( " + tokenFromStack2 + " " + token + " "
					+ tokenFromStack1 + " )";
			operandStack.push(subExpression);
		}
	}
	output = operandStack.top();
	operandStack.pop();
	return output;
}

string ExpressionManager::infixToPostfix(string infixExpression) {
	if (!expressionIsValid(infixExpression)) {
		return "invalid";
	}
	clearStack(operatorStack);

	string output;
	string token;
	stringstream ss;
	ss << infixExpression;

	int loops = 0;
	while (ss >> token) {
		loops++;
		if (isdigit(token[0])) {
			if (output != "") {
				output += " ";
			}
			if (!tokenIsInteger(token)) {
				return "invalid";
			}
			output += token;
		} else if (stringIsOperator(token)) {
			while (!operatorStack.empty()
					&& characterIsOperator(operatorStack.top())) {
				if (getPrecedentScore(token[0])
						>= getPrecedentScore(operatorStack.top())) {
					output += " ";
					output += operatorStack.top();
					operatorStack.pop();
				} else {
					break;
				}

			}
			operatorStack.push(token[0]);
		} else if (characterIsParenthesis(token[0])) {
			if (characterIsLeftParenthesis(token[0])) {
				operatorStack.push(token[0]);
			} else if (characterIsRightParenthesis(token[0])) {
				while (!characterIsLeftParenthesis(operatorStack.top())) {
					output += " ";
					output += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.pop();
			}
		}
	}
	while (!operatorStack.empty()) {
		output += " ";
		output += operatorStack.top();
		operatorStack.pop();
	}

	return output;
}

string ExpressionManager::postfixEvaluate(string postfixExpression) {
	if (postfixExpression
			!= infixToPostfix(postfixToInfix(postfixExpression))) {
		return "invalid";
	} else {
		string output, subExpression, subResult;
		int intFromStack1, intFromStack2;
		string token;
		stringstream ss;
		ss << postfixExpression;

		while (ss >> token) {
			stringstream converter1, converter2;
			if (isdigit(token[0])) {
				operandStack.push(token);
			} else if (characterIsOperator(token[0])) {
				converter1 << operandStack.top();
				converter1 >> intFromStack1;
				operandStack.pop();
				converter2 << operandStack.top();
				converter2 >> intFromStack2;
				operandStack.pop();

				if (evaluateSubExpression(intFromStack1, intFromStack2,
						token[0]) != "invalid") {
					operandStack.push(
							evaluateSubExpression(intFromStack1, intFromStack2,
									token[0]));
				} else {
					return "invalid";
				}
			}
		}
		return operandStack.top();
	}
}
} /* namespace std */
