#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<map>
#include<utility>
#include<string>
#include<vector>
#include"Number.h"
using namespace std;

class Calculator
{
public:
	bool fetchInput();
	Number* compute(string input);
	string input_string();

private:
	map<string, Number *> variables;
	bool isCompute(string input);
	Number* operateVariable(string input, bool *print);
	Number* setVariable(string input, string num);
	Number* setVariable(string input, string num, bool Integer);
	pair<bool, pair<string, string>> validVariableExpression(string expression);
	int getPriority(char op);
	pair<bool, vector<string>> infixToPostfix(string input);
	Number* calculate(Number *operand1, Number *operand2,char op);
};

#endif