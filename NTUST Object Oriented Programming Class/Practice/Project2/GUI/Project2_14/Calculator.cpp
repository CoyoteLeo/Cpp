#include "Calculator.h"
#include "Number.h"
#include "Integer.h"
#include "Decimal.h"
#include <stack>
#define INTEGER 1
#define DECIMAl 2
using namespace std;


bool Calculator::fetchInput()
{
	cout << "Usage:\n<Any Expression> : calculate the result\nclear : clean all variables\noff : turn off the calculator" << endl;
	cout << "Input:" << endl;
	Number*result = NULL;
	bool print = true;
	string input = input_string();
	if (input == "off")
	{
		cout << "Calculator is off!\n" << endl;
		return false;
	}
	else if (input == "clear")
	{
		for (map<string, Number*>::iterator i = variables.begin(); i != variables.end(); ++i)
			delete i->second;
		variables.clear();
		cout << "Clean all variables!\n" << endl;
		return true;
	}
	else if (isCompute(input))
		result = compute(input);
	else if (input != "") {
		print = false;
		result = operateVariable(input, &print);
	}
	if (print)
		if (result == NULL)
			cout << "Compute Error" << endl;
		else if (result->getType()) {

			cout << "Output:" << endl;
			cout << *(Integer*)result << endl;
		}
		else {
			cout << "Output:" << endl;
			cout << *(Decimal*)result << endl;
		}
		cout << endl;
		return true;
}

string Calculator::input_string()
{
	int ch;
	string input("");
	while (((ch = getchar()) != '\n' || input.size() == 0) && ch != EOF)
		if (!isspace(ch))
			input += ch;
	return input;
}

bool Calculator::isCompute(string input)
{
	return input.find('=') == string::npos;
}

Number* Calculator::operateVariable(string input, bool *print)
{
	Number* result = NULL;
	if (input.find("Set") != string::npos)
	{
		int type = (input.find("Integer", 3) == 3 ? INTEGER : (input.find("Decimal", 3) == 3 ? DECIMAl : 0));
		if (type == 0)
		{
			cout << "Variable Type Error" << endl;
			return result;
		}
		pair<bool, pair<string, string>> valid = validVariableExpression(input.substr(10, input.size() - 10));
		if (!valid.first) {
			return result;
		}
		// Set Variable
		result = setVariable(valid.second.first, valid.second.second, type == INTEGER);
	}
	else
	{
		pair<bool, pair<string, string>> valid = validVariableExpression(input);
		if (!valid.first) {
			return result;
		}
		result = setVariable(valid.second.first, valid.second.second);
	}
	return result;
}

pair<bool, pair<string, string>> Calculator::validVariableExpression(string expression)
{
	pair<bool, pair<string, string>> result(true, pair<string, string>("", ""));
	int equalPosition = expression.find("=");

	string name = expression.substr(0, equalPosition);
	if (name.size() < 1)
	{
		result.first = false;
		cout << "Variable Name Error" << endl;
	}
	else
		result.second.first = expression.substr(0, equalPosition);

	if (equalPosition + 1 >= expression.size())
	{
		result.first = false;
		cout << "Set Variable Expression Error" << endl;
	}
	else
		result.second.second = expression.substr(equalPosition + 1, expression.size() - equalPosition);

	if (!isCompute(result.second.second)) {
		result.first = false;
		cout << "Invalid Value" << endl;
	}

	return result;
}

Number* Calculator::setVariable(string name, string num, bool integer)
{
	Number* result = compute(num);
	if (result != NULL)
		if (integer)
			if (result->getType())
				variables[name] = new Integer(*(Integer*)result);
			else
				variables[name] = new Integer(*(Decimal*)result);
		else
			if (result->getType())
				variables[name] = new Decimal(*(Integer*)result);
			else
				variables[name] = new Decimal(*(Decimal*)result);
	return variables[name];
}

Number* Calculator::setVariable(string name, string num)
{
	if (variables.count(name))
	{
		Number* result = compute(num);
		if (variables[name]->getType())
			if (result->getType())
				variables[name] = new Integer(*(Integer*)result);
			else
				variables[name] = new Integer(*(Decimal*)result);
		else
			if (result->getType())
				variables[name] = new Decimal(*(Integer*)result);
			else
				variables[name] = new Decimal(*(Decimal*)result);
		return variables[name];
	}
	else
	{
		cout << "Variable is not exist" << endl;
		return NULL;
	}
}

Number* Calculator::compute(string input)
{
	pair<bool, vector<string>> postfix = infixToPostfix(input);
	bool error = false;
	Number *result = NULL;
	if (!postfix.first) {
		cout << postfix.second[0] << endl;
		return NULL;
	}
	else
	{
		vector<string> expression(postfix.second);
		stack<Number*> operand;
		Number *operand1, *operand2;
		for (unsigned int i = 0; i < expression.size() && !error; i++)
		{
			if (expression[i] == "!")
			{
				if (operand.size() < 1)
				{
					cout << "Expression Error" << endl;
					error = true;
					break;
				}
				operand1 = operand.top();
				operand.pop();
				if (operand1->getType() && *(Integer*)operand1 >= Integer(0))
					operand.push(new Integer((*(Integer*)operand1).factorial()));
				else if (!operand1->getType() && *(Decimal*)operand1 >= Decimal("0") && isDecimalToInteger(*(Decimal*)operand1))
					operand.push(new Decimal((*(Decimal*)operand1).factorial()));
				else
				{
					cout << "Negative or the number after Decimal's not zero can't do factorial" << endl;
					error = true;
					break;
				}
				delete operand1;
			}
			else if (expression[i].size() == 1 && getPriority(expression[i][0]) > 0)
			{
				if (operand.size() < 2)
				{
					cout << "Expression Error" << endl;
					error = true;
					break;
				}
				operand2 = operand.top();
				operand.pop();
				operand1 = operand.top();
				operand.pop();
				switch (expression[i][0])
				{
				case '/':
					if ((operand2->getType() && *(Integer*)operand2 == Integer(0)) || (!operand2->getType() && *(Decimal*)operand2 == Decimal("0"))) {
						cout << "Divider can't be Zero" << endl;
						error = true;
						break;
					}

				case '^':
					if ((!operand2->getType() && !isDecimalToInteger(*(Decimal*)operand2)) &&
						((operand1->getType() && *(Integer*)operand1 < Integer(0)) ||
						(!operand1->getType() && *(Decimal*)operand1 < Decimal("0"))))
					{
						cout << "Negative can't do root" << endl;
						error = true;
						break;
					}
				case '+':
				case '-':
				case '*':
					operand.push(calculate(operand1, operand2, expression[i][0]));
					delete operand1;
					delete operand2;
					break;
				default:
					cout << "Unknown Operator" << endl;
					error = true;
					break;
				}
			}
			else
			{
				if (isInteger(expression[i]))
					operand.push(new Integer(expression[i]));
				else if (isDecimal(expression[i]))
					operand.push(new Decimal(expression[i]));
				else if (variables.count(expression[i])) {
					Number* variable = variables[expression[i]];
					if (variable->getType())
						operand.push(new Integer(*(Integer*)variable));
					else
						operand.push(new Decimal(*(Decimal*)variable));
				}
				else
				{
					cout << "Operand Error!" << endl;
					error = true;
					break;
				}
			}
		}
		if (operand.size() != 1 || error)
		{
			while (operand.size() > 0) {
				delete operand.top();
				operand.pop();
			}
			if (!error)
				cout << "Expression Error" << endl;
			return result;
		}
		else
		{
			result = operand.top();
			return result;
		}
	}
}

Number* Calculator::calculate(Number* operand1, Number* operand2, char op)
{
	bool new_type = operand1->getType() && operand2->getType();
	Integer *i1 = NULL, *i2 = NULL;
	Decimal *d1 = NULL, *d2 = NULL;
	if (operand1->getType())
		i1 = (Integer *)operand1;
	else
		d1 = (Decimal *)operand1;
	if (operand2->getType())
		i2 = (Integer *)operand2;
	else
		d2 = (Decimal *)operand2;
	switch (op) {
	case'+':
		if (i1 != NULL && i2 != NULL)
			return new Integer(*i1 + *i2);
		if (i1 != NULL && d2 != NULL)
			return new Decimal(*i1 + *d2);
		if (d1 != NULL && i2 != NULL)
			return new Decimal(*d1 + *i2);
		if (d1 != NULL && d2 != NULL)
			return new Decimal(*d1 + *d2);
	case'-':
		if (i1 != NULL && i2 != NULL)
			return new Integer(*i1 - *i2);
		if (i1 != NULL && d2 != NULL)
			return new Decimal(*i1 - *d2);
		if (d1 != NULL && i2 != NULL)
			return new Decimal(*d1 - *i2);
		if (d1 != NULL && d2 != NULL)
			return new Decimal(*d1 - *d2);
	case'*':
		if (i1 != NULL && i2 != NULL)
			return new Integer(*i1 * *i2);
		if (i1 != NULL && d2 != NULL)
			return new Decimal(*i1 * *d2);
		if (d1 != NULL && i2 != NULL)
			return new Decimal(*d1 * *i2);
		if (d1 != NULL && d2 != NULL)
			return new Decimal(*d1 * *d2);
	case'/':
		if (i1 != NULL && i2 != NULL)
			return new Integer(*i1 / *i2);
		if (i1 != NULL && d2 != NULL)
			return new Decimal(*i1 / *d2);
		if (d1 != NULL && i2 != NULL)
			return new Decimal(*d1 / *i2);
		if (d1 != NULL && d2 != NULL)
			return new Decimal(*d1 / *d2);
	case'^':
		if (i1 != NULL && i2 != NULL)
			return new Integer(*i1 ^ *i2);
		if (i1 != NULL && d2 != NULL){
			if (!(*d2 - Integer(*d2) == Decimal(Integer(1), Integer(2))) && !(*d2 == Decimal(Integer(*d2)))) {
				cout << "root must be 0.5 times" << endl;
				return NULL;
			}
		return new Decimal(*i1 ^ *d2);
		}
		if (d1 != NULL && i2 != NULL)
			return new Decimal(*d1 ^ *i2);
		if (d1 != NULL && d2 != NULL){
			if (!(*d2 - Integer(*d2) == Decimal(Integer(1), Integer(2)))&&!(*d2==Decimal(Integer(*d2)))) {
				cout << "root must be 0.5 times" << endl;
				return NULL;
			}
			return new Decimal(*d1 ^ *d2);
		}
	default:
		return NULL;
	}
}

int Calculator::getPriority(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 4;
	case '(':
	case ')':
		return -1;
	case '!':
	default:
		return 0;
	}
}

pair<bool, vector<string>> Calculator::infixToPostfix(string input)
{
	vector<string> result;
	bool preIsOperator = false;
	int left_parameter = 0;
	string num;
	stack<char> op;
	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (getPriority(input[i]) == 0)  // exclude operator
			num.push_back(input[i]);
		else  // operator
		{
			// operand

			if (num == "" && (input[i - 1] != ')' && ((input[i] == '-') || (input[i] == '+'))))
			{
				if (input[i] == '-')
				{
					result.push_back(string("-1"));
					op.push('*');
				}
				continue;
			}

			//else
			if (true)
			{
				if (num != "")
				{
					if (input[i] == '(')
					{
						if (i + 1 == input.size() - 1 || input[i + 1] == ')') {
							vector<string> temp;
							temp.push_back("Parentheses Error");
							return pair<bool, vector<string>>(false, temp);
						}
						op.push('*');
					}
					if (num.back() == '!')
					{
						int temp = num.find('!');
						if (temp>0)
							result.push_back(num.substr(0, temp));
						while (temp < num.size() && num[temp++] == '!')
							result.push_back("!");
					}
					else
						result.push_back(num);
					num.clear();
				}
				if (input[i] == '(')
				{
					++left_parameter;
					op.push('(');
				}
				else if (input[i] == ')')
				{
					if (left_parameter < 1)
					{
						vector<string> temp;
						temp.push_back("Parentheses don't match!");
						return pair<bool, vector<string>>(false, temp);
					}
					else
					{
						--left_parameter;
						while (!op.empty() && op.top() != '(')
						{
							result.push_back(string(1, op.top()));
							op.pop();
						}
						op.pop();
					}
				}
				else
				{
					while (!op.empty() && getPriority(op.top()) >= getPriority(input[i]))
					{
						if (op.top() == '^' && input[i] == '^')
							break;
						result.push_back(string(1, op.top()));
						op.pop();
					}
					op.push(input[i]);
				}
			}
		}
	}
	if (num != "")
	{
		if (num.back() == '!')
		{
			int temp = num.find('!');
			if (temp>0)
				result.push_back(num.substr(0, temp));
			while (temp < num.size() && num[temp++] == '!')
				result.push_back("!");
		}
		else
			result.push_back(num);
		num.clear();
	}

	while (!op.empty())
	{
		result.push_back(string() + op.top());
		op.pop();
	}
	/*
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	*/
	return pair<bool, vector<string>>(true, result);
}
