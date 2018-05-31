#include "Integer.h"
#include "Decimal.h"
#include "Number.h"
#include "Calculator.h"

Integer::Integer() : Number(true),sign(true)
{
}

Integer::Integer(string input) : Number(true)
{
	if (input[0] == '-')
	{
		sign = 0;
		input.erase(input.begin());
	}
	else
	{
		sign = 1;
	}

	for (int i = input.size() - 1; i >= 0; i--)
		if (input[i] == '.')
			numArray.clear();
		else
			numArray.push_back(input[i] - '0');
	if (numArray.size() < 1)
		numArray.push_back(0);
	popZero();
}

Integer::Integer(bool sign_, vector<int> numArray_) : Number(true), sign(sign_), numArray(numArray_)
{
	popZero();
}

Integer::Integer(int n) : Number(true)
{
	if (n < 0)
		sign = 0;
	else
		sign = 1;

	if (n == 0)
		numArray.push_back((0));
	else
		while (n > 0)
		{
			numArray.push_back((n % 10));
			n /= 10;
		}
	popZero();
}

Integer::Integer(const Integer &obj) : Number(true),sign(obj.sign), numArray(obj.numArray)
{
}

Integer::Integer(const Decimal &decimal) : Number(true)
{
	*this = decimal.getNumerator() / decimal.getDenominator();
}

Integer::Integer(const char input[])
{
	Calculator c;
	string input_str(input);
	int position = input_str.find(' ');
	while (position != string::npos){
		input_str.erase(position, 1);
		position = input_str.find(' ');
	}
	Number* result=c.compute(input_str);
	if (result == NULL)
		*this = Decimal();
	else if (result->getType())
		*this = *(Integer*)result;
	else
		*this = Integer(*(Decimal*)result);
}

Integer::~Integer()
{
}

Integer Integer::operator+()
{
	return *this;
}

Integer Integer::operator-()
{
	return Integer(!sign, numArray);
}

bool Integer::operator>(Integer integer)
{
	if (sign && !integer.sign)  // + -
		return true;
	else if (!sign && integer.sign)  // - +
		return false;
	else  // + + or - -
	{
		int size1 = numArray.size(), size2 = integer.numArray.size();
		if ((sign && size1 > size2) || (!sign && size2 > size1))
			return true;
		else if ((sign && size1 < size2) || (!sign && size2 < size1))
			return false;
		else
		{
			for (int i = size1 - 1; i > -1; i--)
				if ((sign && numArray[i] < integer.numArray[i]) || (!sign && numArray[i] > integer.numArray[i]))
					return false;
				else if ((sign && numArray[i] > integer.numArray[i]) || (!sign && numArray[i] < integer.numArray[i]))
					return true;
			return false;
		}
	}
}

bool Integer::operator<(Integer integer)
{
	if (sign && !integer.sign)  // + -
		return false;
	else if (!sign && integer.sign)  // - +
		return true;
	else  // + + or - -
	{
		int size1 = numArray.size(), size2 = integer.numArray.size();
		if ((sign && size1 > size2) || (!sign && size1 < size2))
			return false;
		else if ((sign && size1 < size2) || (!sign && size1 > size2))
			return true;
		else
		{
			for (int i = size1 - 1; i > -1; i--)
				if ((sign && numArray[i] > integer.numArray[i]) || (!sign && numArray[i] < integer.numArray[i]))
					return false;
				else if ((sign && numArray[i] < integer.numArray[i]) || (!sign && numArray[i] > integer.numArray[i]))
					return true;
			return false;
		}
	}
}

bool Integer::operator==(Integer integer)
{
	if (sign != integer.sign || numArray.size() != integer.numArray.size())
		return false;
	else
		for (unsigned int i = 0; i < numArray.size(); i++)
			if (numArray[i] != integer.numArray[i])
				return false;
	return true;
}

bool Integer::operator<=(Integer integer)
{
	return *this<integer || *this == integer;
}

bool Integer::operator>=(Integer integer)
{
	return *this>integer || *this == integer;
}

bool Integer::operator!=(Integer integer)
{
	if (*this == integer)
		return false;
	else
		return true;
}

void Integer::setNumber(string num)
{
	for (int i = 0; i < num.size(); i++)
		if (numArray[i] == '.')
			break;
		else
			numArray.insert(numArray.begin(), num[i] - '0');
	popZero();
}

Integer Integer::operator+(Integer add)
{
	Integer result;
	vector<int> adder = numArray;
	vector<int> bigNum;
	vector<int> smallNum;

	if ((sign ^ add.sign))
	{
		if (sign)
		{
			return *this - (-add);
		}
		else
		{
			return add - -(*this);
		}
	}

	if ((sign&&*this >= add) ||(!sign&& *this <= add))
	{  //�P�_���
		bigNum = adder;
		smallNum = add.numArray;
	}
	else
	{
		bigNum = add.numArray;
		smallNum = adder;
	}

	for (int i = 0; i < smallNum.size(); i++)
	{  //�����[
		bigNum[i] += smallNum[i];
	}

	for (int i = 0; i < bigNum.size(); i++)
	{  //�B�zcarry
		if (bigNum[i] > 9)
		{
			if (i + 1 >= bigNum.size())
			{
				bigNum.push_back(bigNum[i] / 10);
				bigNum[i] %= 10;
			}
			else
			{
				bigNum[i + 1] += bigNum[i] / 10;
				bigNum[i] %= 10;
			}
		}
	}

	result.sign = (sign);
	result.numArray = (bigNum);

	result.popZero();

	return result;
}

Integer Integer::operator-(Integer sub)
{
	// cout <<"�Q��� : "<< *this << endl;
	// cout <<"��� : "<< sub << endl;

	Integer result;
	vector<int> reduced = numArray;
	vector<int> bigNum;
	vector<int> smallNum;

	if ((sign ^ sub.sign))
	{
		if (sign)
		{  //��-�t
			return *this + (-sub);
		}
		else
		{  //�t-��
			return -(-*this + sub);
		}
	}

	if ((sign &&*this > sub)|| (!sign &&*this < sub))
	{  //�P�_��� �j�p
		result.sign = (1);
		bigNum = reduced;
		smallNum = sub.numArray;
		// cout << 1 << endl;
	}
	else if ((sign &&*this < sub) || (!sign &&*this > sub))
	{
		result.sign = (0);
		bigNum = sub.numArray;
		smallNum = reduced;
		// cout << 2 << endl;
	}
	else
	{
		return Integer(0);
	}
	for (int i = 0; i < smallNum.size(); i++)
	{  //������
		bigNum[i] -= smallNum[i];
	}

	for (int i = 0; i < bigNum.size(); i++)
	{  //�B�zcarry
		while (bigNum[i] < 0)
		{
			bigNum[i + 1] -= 1;
			bigNum[i] += 10;
		}
	}
	result.numArray = (bigNum);

	result.popZero();

	return result;
}

Integer Integer::operator*(Integer mul)
{
	Integer result;

	vector<int> temp;
	temp.resize(numArray.size() + mul.numArray.size());
	for (int i = 0; i < numArray.size(); i++)
	{  //���������k
		for (int j = 0; j < mul.numArray.size(); j++)
		{
			temp[i + j] += numArray[i] * mul.numArray[j];
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{  //�B�zcarry
		if (temp[i] > 9)
		{
			if (i + 1 >= temp.size())
				temp.push_back(temp[i] / 10);
			else
				temp[i + 1] += temp[i] / 10;
			temp[i] %= 10;
		}
	}

	result.numArray = (temp);

	result.sign = (!(sign ^ mul.sign));

	result.popZero();

	return result;
}

Integer Integer::operator/(Integer divid)
{
	Integer result;
	Integer remainder;
	vector<int> quotient;

	result.sign = (!(sign ^ divid.sign));
	divid.sign = (1);

	Integer h = *this;
	h.sign = (1);

	vector<int> remainder_temp = h.numArray;

	while (!remainder_temp.empty()) {
		vector<int> temp = remainder.numArray;

		if (temp.size() == 1 && temp[0] == 0)temp.erase(temp.begin());
		if (remainder_temp.empty()) {
			temp.insert(temp.begin(), 0);
		}
		else {
			temp.insert(temp.begin(), remainder_temp[remainder_temp.size() - 1]);
			remainder_temp.pop_back();
		}

		remainder.numArray = (temp);

		for (int i = 9; i >= 0; i--) {
			Integer  quotient_temp(i);
			if (!(remainder < divid * quotient_temp)) {
				remainder = remainder - divid * quotient_temp;
				quotient.insert(quotient.begin(), i);
				break;
			}
		}
	}

	result.numArray = (quotient);
	result.popZero();
	return result;
}

Decimal Integer::operator+(Decimal add)
{
	return Decimal(*this) + add;
}

Decimal Integer::operator-(Decimal sub)
{
	return Decimal(*this) - sub;
}

Decimal Integer::operator*(Decimal mul)
{
	return Decimal(*this) * mul;
}

Decimal Integer::operator/(Decimal divid)
{
	return Decimal(*this) / divid;
}

Integer& Integer::operator=(const Integer &obj)
{
	sign = obj.sign;
	numArray.clear();
	for (int i = 0; i < obj.numArray.size(); i++)
	{
		numArray.push_back(obj.numArray[i]);
	}
	return *this;
}

Integer &Integer::operator=(const Decimal &obj)
{
	*this = (obj.getNumerator() / obj.getDenominator());
	return *this;
}

void Integer::popZero()
{
	for (int i = numArray.size() - 1; i > 0; i--)
	{ 
		if (numArray[i] == 0)
			numArray.erase(numArray.begin() + i);
		else
			break;
	}

	for (int i = 0; i < 0; i++)
	{   
		if (numArray[i] == 0)
		{
			numArray.erase(numArray.begin() + i);
			i = -1;
		}
		else
			break;
	}

	if (numArray.size() == 1 && numArray[0] == 0 || numArray.size() == 0)
	{  
		sign = 1;
	}
}

Integer gcd(Integer m, Integer n)
{
	Integer zero(0), r;
	while (n != zero)
	{
		r = m / n;
		r = m - n * r;
		m = n;
		n = r;
	}

	return m;
}

Integer Integer::operator^(Integer power)
{
	Integer factor = *this, one(1), two(2);
	Integer result = one;

	if (power.sign == 0)
	{
		power.sign = (1);
		Integer swap = power;
		factor = one / factor;
	}

	if (power == Integer(0))
		return one;
	else if (power == one)
		return factor;
	else
	{
		while (power > one)
		{
			if ((power.numArray[0] & 1) == 0) {
				factor = factor * factor;
				power = power / two;
			}
			else {
				result = result * factor;
				power.numArray[0] -= 1;
			}
		}
	}

	return factor * result;
}

Decimal Integer::operator^(Decimal powerDec)
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

Integer Integer::factorial()
{
	Integer result(1),one(1);

	for (Integer i = *this; i > one; i = (i - one)) {
		result = result * i;
	}

	return result;
}

Decimal Integer::root()
{
	Integer targetInt;
	targetInt = (*this);
	vector<int>targetTemp = targetInt.getNumArray();
	Decimal targetDec = (*this) - targetInt;

	Integer numerator = targetDec.getNumerator();
	Integer denominator = targetDec.getDenominator();
	Integer one(1), nine(9), ten(10), zero(0);

	while (!(numerator == zero)) {
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

	int floatPoint = 0;
	while (floatPoint < 200) {

		if (temp.getNumArray().size() % 2 == 1) {
			arr.clear();
			arr.insert(arr.begin(), temp.getNumArray()[temp.getNumArray().size() - 1]);
			temp2.setNumArray(arr);
			arr = temp.getNumArray();
			arr.pop_back();
			temp.setNumArray(arr);
			//cout << "ya" << endl;
		}
		else {
			if (temp.getNumArray().size() <= 0) {
				arr = temp2.getNumArray();
				arr.insert(arr.begin(), 0);
				arr.insert(arr.begin(), 0);
				temp2.setNumArray(arr);
				//cout << "yaya" << endl;
			}
			else {
				for (int i = 0; i < 2 && temp.getNumArray().size() >= 1; i++) {
					arr = temp2.getNumArray();
					arr.insert(arr.begin(), temp.getNumArray()[temp.getNumArray().size() - 1]);
					temp2.setNumArray(arr);
					arr = temp.getNumArray();
					arr.pop_back();
					temp.setNumArray(arr);
				}
			}

		}

		resultTemp = result * Integer(20);
		
		temp2.popZero();
		for (Integer i = nine; !(i < zero); i = i - one) {

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
	//return result;
	return Decimal(result, ten ^ (floatPoint));
}

std::ostream &operator<<(std::ostream &outputStream, Integer output)
{
	output.popZero();

	if (output.sign == 0)
	{
		outputStream << '-';
	}

	for (int i = output.numArray.size() - 1; i >= 0; i--)
	{
		outputStream << output.numArray[i];
	}

	return outputStream;
}

std::istream &operator>>(std::istream &inputStream, Integer &input)
{
	Calculator c;
	string in = c.input_string();
	Number* result = c.compute(in);
	/*
	string temp;
	inputStream >> temp;

	vector<int> numtemp;

	if (temp[0] == '-')
	{
		input.sign = (0);
		temp.erase(temp.begin());
	}
	else
	{
		input.sign = (1);
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '.')
			break;
		else
			numtemp.insert(numtemp.begin(), temp[i] - '0');
	}

	input.numArray = (numtemp);
	*/
	if (result == NULL)
		input = Integer(0);
	else if (result->getType())
		input = *(Integer*)result;
	else
		input = Integer(*(Decimal*)result);
	return inputStream;
}

vector<int> Integer::getNumArray()
{
	return numArray;
}

void Integer::setNumArray(vector<int> n)
{
	numArray = n;
}

void Integer::minusOneLastDigit()
{
	numArray[0] -= 1;
}

bool Integer::getSign()
{
	return sign;
}

void Integer::setSign(bool sign_)
{
	sign = sign_;
}

bool isInteger(string input)
{
	unsigned int i = (input[0] == '-' ? 1 : 0);
	for (; i < input.size(); i++)
		if (input[i] == '.' || !isdigit(input[i]))
			return false;
	return true;
}
