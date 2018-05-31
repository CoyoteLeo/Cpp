#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<map>
#include<utility>
#include<string>
#include<vector>
#include"Number.h"
//using namespace std;

class Calculator
{
public:
	bool fetchInput();
	Number* compute(std::string input);
	std::string input_string();
	Number* operateVariable(std::string input, bool *print);

private:
	std::map< std::string, Number *> variables;
	bool isCompute(std::string input);

	Number* setVariable(std::string input, std::string num);
	Number* setVariable(std::string input, std::string num, bool Integer);
	std::pair<bool, std::pair< std::string, std::string>> validVariableExpression(std::string expression);
	int getPriority(char op);
	std::pair<bool, std::vector< std::string>> infixToPostfix(std::string input);
	Number* calculate(Number *operand1, Number *operand2,char op);
};

#endif