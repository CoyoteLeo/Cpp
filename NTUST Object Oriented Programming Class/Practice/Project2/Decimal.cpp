#include "Decimal.h"
#include "Integer.h"
#include "Number.h"
#include "Calculator.h"
#include <cctype>
#include<ctime>

Decimal::Decimal() : Number(false), numerator(new Integer(0)), denominator(new Integer(1))
{
}

Decimal::Decimal(string input) : Number(false), numerator(new Integer(0)), denominator(new Integer(0))
{
	delete numerator;
	delete denominator;
	int start = 0;
	if (input[0] == '-')
	{
		start = 1;
	}

	vector<int> pushNumerator, pushDenominator;
	int position = input.size() - 1;
	bool have_dot = false;
	for (; position >= start; position--)
	{
		if (input[position] == '.')
		{
			unsigned int denominator_size = input.size() - position - 1;
			while (denominator_size-- > 0)
				pushDenominator.push_back(0);
		}
		else
		{
			pushNumerator.push_back(input[position] - '0');
		}
	}

	pushDenominator.push_back(1);
	denominator = new Integer(true, pushDenominator);
	numerator = new Integer(start == 0, pushNumerator);
	//this->fraction_reduction();
}

Decimal::Decimal(Integer integer) :Number(false), numerator(new Integer(integer)), denominator(new Integer(1))
{
}

Decimal::Decimal(Integer numerator_, Integer denominator_)
	: Number(false), numerator(new Integer(numerator_)), denominator(new Integer(denominator_))
{
	//this->fraction_reduction();
}

Decimal::Decimal(const Decimal &obj) : Number(false), numerator(new Integer(*obj.numerator)), denominator(new Integer(*obj.denominator))
{
}

Decimal::Decimal(const char input[])
{
	Calculator c;
	string input_str(input);
	int position = input_str.find(' ');
	while (position != string::npos) {
		input_str.erase(position, 1);
		position = input_str.find(' ');
	}
	Number* result = c.compute(input_str);
	if (result == NULL)
		*this = Decimal();
	else if (result->getType())
		*this = Decimal(*(Integer*)result);
	else
		*this = *(Decimal*)result;
	//this->fraction_reduction();
}

Decimal::~Decimal()
{
	delete numerator;
	numerator = NULL;
	delete denominator;
	denominator = NULL;
}

void Decimal::setNumber(string num)
{
	*this = Decimal(num);
}

Decimal& Decimal::operator=(Decimal copy)
{
	numerator = new Integer(*copy.numerator);
	denominator = new Integer(*copy.denominator);
	return *this;
}

Decimal & Decimal::operator=(Integer integer)
{
	delete numerator;
	delete denominator;
	numerator = new Integer(integer);
	denominator = new Integer(1);
	return *this;
}

bool Decimal::operator>(Decimal d)
{
	return (*numerator)* (*d.denominator) > (*denominator) * (*d.numerator);
}

bool Decimal::operator<(Decimal d)
{
	return (*numerator)* (*d.denominator) < (*denominator) * (*d.numerator);
}

bool Decimal::operator==(Decimal d)
{
	return (*numerator)* (*d.denominator) == (*denominator) * (*d.numerator);
}

bool Decimal::operator>=(Decimal decimal)
{
	return *this>decimal || *this == decimal;
}

Decimal Decimal::operator+()
{
	return Decimal(*numerator, *denominator);
}

Decimal Decimal::operator-()
{
	return Decimal(-*numerator, *denominator);
}

Decimal Decimal::operator+(Decimal decimal)
{
	Decimal result = Decimal((*numerator) * (*(decimal.denominator)) + (*(decimal.numerator)) * (*denominator),
		(*denominator) * (*(decimal.denominator)));
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator+(Integer integer)
{
	Decimal result = *this + Decimal(integer);
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator-(Decimal decimal)
{
	Decimal result = Decimal((*numerator) * (*(decimal.denominator)) - (*(decimal.numerator)) * (*denominator),
		(*denominator) * (*(decimal.denominator)));
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator-(Integer integer)
{
	Decimal result = *this - Decimal(integer);
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator*(Decimal decimal)
{
	Decimal result = Decimal((*numerator) * (*(decimal.numerator)), (*denominator) * (*(decimal.denominator)));
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator*(Integer integer)
{
	Decimal result = *this * Decimal(integer);
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator/(Decimal decimal)
{
	Decimal result = Decimal((*numerator) * (*(decimal.denominator)), (*denominator) * (*(decimal.numerator)));
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::operator/(Integer integer)
{
	Decimal result = *this / Decimal(integer);
	// result.fraction_reduction();
	return result;
}

Integer Decimal::getNumerator() const
{
	return *numerator;
}

Integer Decimal::getDenominator() const
{
	return *denominator;
}

Decimal Decimal::operator^(Decimal powerDec)
{
	bool negative = false;
	if (powerDec.getNumerator().getSign() ^ powerDec.getDenominator().getSign()) {
		powerDec = -powerDec;
		negative = true;
	}
	Integer one(1), zero(0), two(2);
	Decimal result(one, one);
	Integer powerInt(powerDec);
	Decimal factor = *this, temp = *this;
	powerDec = powerDec - powerInt;

	if (powerInt == zero)
	{
		//do nothing
	}
	else if (powerInt == one)
		result = factor;
	else
	{
		while (powerInt > one)
		{
			if ((powerInt.getNumArray()[0] & 1) == 0) {
				factor = factor * factor;
				powerInt = powerInt / two;
			}
			else {
				result = result * factor;
				powerInt.minusOneLastDigit();
			}
		}
		result = result * factor;
	}

	if (powerDec == Decimal(Integer(1), Integer(2))) {
		result = result * (*this).root();
	}
	if (negative)
		result = Decimal("1") / result;
	return result;
}

Decimal Decimal::operator^(Integer power)
{

	Decimal factor = *this, one(1, 1), two(2, 1);
	Decimal result = one;

	if (power.getSign() == 0)
	{
		factor = one / factor;
		power.setSign(1);
	}

	if (power == Integer(0))
		return one;
	else if (power == one)
		return factor;
	else
	{
		while (power > one)
		{
			if ((power.getNumArray()[0] & 1) == 0) {
				factor = factor * factor;
				power = power / two;
			}
			else {
				result = result * factor;
				power.minusOneLastDigit();
			}
		}
	}

	/////////////////////////////////////////
	//Decimal temp = factor * result;
	//cout << ((float)(clock()-start)) / CLOCKS_PER_SEC << endl;
	////////////////////////////////////////
	return factor * result;
}

Decimal Decimal::factorial()
{
	Decimal result = Decimal(((this->getNumerator()) / (this->getDenominator())).factorial());
	// result.fraction_reduction();
	return result;
}

Decimal Decimal::root()
{
	Integer targetInt;
	targetInt = (*this);
	vector<int>targetTemp = targetInt.getNumArray();
	Decimal targetDec = (*this) - targetInt;

	Integer numerator = *targetDec.numerator;
	Integer denominator = *targetDec.denominator;
	Integer zero(0), one(1), ten(10);

	while (!(numerator == Integer(0))) {
		targetTemp.insert(targetTemp.begin(), ((numerator*ten) / denominator).getNumArray()[0]);
		numerator = ((numerator*ten) - denominator * ((numerator*ten) / denominator));
	}

	targetDec = targetDec + targetInt;

	Integer result;
	Integer resultTemp;

	Integer temp;
	temp.setNumArray(targetTemp);
	Integer temp2;
	vector<int>arr;

	bool single = targetInt.getNumArray().size() % 2;

	int floatPoint = 0;
	while (floatPoint < 100) {

		if (temp.getNumArray().size() % 2 == 1 && single || single) {
			arr.clear();
			arr.insert(arr.begin(), temp.getNumArray()[temp.getNumArray().size() - 1]);
			temp2.setNumArray(arr);
			arr = temp.getNumArray();
			arr.pop_back();
			temp.setNumArray(arr);
			single = false;
		}
		else {
			if (temp.getNumArray().size() <= 0) {
				arr = temp2.getNumArray();
				arr.insert(arr.begin(), 0);
				arr.insert(arr.begin(), 0);
				temp2.setNumArray(arr);
			}
			else {
				for (int i = 0; i < 2; i++) {
					if (temp.getNumArray().size() < 1) {
						arr = temp2.getNumArray();
						arr.insert(arr.begin(), 0);
						temp2.setNumArray(arr);
						//floatPoint++;
						//system("pause");
						break;
					}
					else {
						arr = temp2.getNumArray();
						arr.insert(arr.begin(), temp.getNumArray()[temp.getNumArray().size() - 1]);
						temp2.setNumArray(arr);
						arr = temp.getNumArray();
						arr.pop_back();
						temp.setNumArray(arr);
					}

				}
			}

		}
		resultTemp = result * Integer(20);
		temp2.popZero();
		
		for (Integer i(9); !(i < zero); i = i - one) {
			Integer test = ((resultTemp + i)*i);
			if (!(test > temp2)) {
				temp2 = temp2 - test;
				if (result.getNumArray().size() * 2 >= targetInt.getNumArray().size()) {
					floatPoint++;
					vector<int>t = result.getNumArray();
					t.insert(t.begin(), i.getNumArray()[0]);
					result.setNumArray(t);
				}
				else {
					vector<int>t = result.getNumArray();
					t.insert(t.begin(), i.getNumArray()[0]);
					result.setNumArray(t);
				}
				break;
			}

		}
	}
	return Decimal(result, Integer(10) ^ (floatPoint));
}

void Decimal::fraction_reduction()
{
	Integer gcd_num = gcd(*numerator, *denominator);
	*numerator = *numerator / gcd_num;
	*denominator = *denominator / gcd_num;
}

std::ostream & operator<<(std::ostream & outputStream, Decimal output)
{

	if ((output.numerator->getSign()) ^ (output.denominator->getSign()))
		cout << '-';

	Integer result = (output.getNumerator()) / (output.getDenominator());
	vector<int>resultTemp = result.getNumArray();

	Integer numerator = (output - result).getNumerator();
	Integer denominator = output.getDenominator();
	Integer ten(10);

	int floatPoint = 0;
	while (floatPoint < 100) {
		resultTemp.insert(resultTemp.begin(), ((numerator*ten) / denominator).getNumArray()[0]);
		numerator = ((numerator*ten) - denominator * ((numerator*ten) / denominator));
		floatPoint++;
	}

	for (int i = resultTemp.size() - 1; i >= 0; i--) {
		if (i == resultTemp.size() - 1 - result.getNumArray().size())
			outputStream << '.';
		outputStream << resultTemp[i];
	}
	return outputStream;
}

std::istream & operator>>(std::istream & inputStream, Decimal &input)
{
	Calculator c;
	string in = c.input_string();
	Number* result = c.compute(in);
	/*
	string temp;
	inputStream >> temp;
	input = Decimal(temp);
	*/
	if(result==NULL)
		input = Decimal("0");
	else if (result->getType())
		input = Decimal(*(Integer*)result);
	else
		input = *(Decimal*)result;
	return inputStream;
}

bool isDecimalToInteger(Decimal input)
{
	return input - Integer(input) == Decimal("0");
}

bool isDecimal(string input)
{
	unsigned int i = (input[0] == '-' ? 1 : 0);
	bool have_dot = false;
	for (; i < input.size(); i++)
	{
		if (input[i] == '.')
			if (have_dot)
				return false;
			else
				have_dot = true;
		else if (!isdigit(input[i]))
			return false;
	}
	return true;
}
