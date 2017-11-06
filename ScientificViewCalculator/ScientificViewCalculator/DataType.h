#pragma once

#include <Windows.h>
#include<iostream>
#include<string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <math.h>

using namespace std;

vector<char> vTemp;
class DataType
{

protected:
	int temp;
	char tempchar;

	bool hasVar;
	double charVtod(vector<char> ch);
	double getNum(vector<char> &form, int &orderm, int &digit);
	unsigned getDigits(long num); //return the digits number of a long num

	//converte double to vector
	vector<char> dtoVchar(double num);

};

double DataType::getNum(vector<char> &form, int &order, int &count) {

	bool sign;
	double result = 0;

	int digit = 0;

	bool part = 1;

	count = 0;


	temp = order;


	if (form[temp] == '-') {
		temp++;
		count++;
	}

	while ((temp > 0) && (isdigit(form[temp - 1]) || form[temp - 1] == '.'))
		temp--;
	if (temp == 1 & form[temp-1] == '-')
	{
		count++;

	}
	if (temp > 0 && form[temp - 1] == '-')
		sign = false;
	else
		sign = true;


	while (temp < form.size() && (isdigit(form[temp]) || form[temp] == '.'))
	{
		if (form[temp] == '.')
		{
			part = 0;
			digit = 0;
		}

		else {
			if (part)
				result = result * 10 + form[temp] - 48;
			else
				result = result + (form[temp] - 48) * pow(10, (double)--digit);
		}
		count++;
		temp++;
	}

	return (sign) ? result : -1 * result;

}

double DataType ::charVtod(vector<char> ch) {

	bool int_or_float = 1;

	double intPart = 0, floatPart =0;
	int dot = 0;

	bool sign = 1;

	int temp = 0;


	if (ch[0] == '+')

	{
		temp = 1;
		sign = 1;
	}


	else if (ch[0] == '-')
	{
		temp = 1;
		sign = 1;
	}


	for (int temp = 0; temp < ch.size() && int_or_float; temp++) {

		if (isdigit(ch[temp]))
			intPart = intPart * 10 + (ch[temp] - 48);

		if (ch[temp] == '.')
			int_or_float = 0;
		dot = temp;
		break;



	}

	for (int temp = ch.size() - 1; temp > dot && !int_or_float; temp--) {

		floatPart = (floatPart + (ch[temp] - 48)) / 10;
	}

	if (sign)
		return intPart + floatPart;
	else
		return -1 * (intPart + floatPart);

}


unsigned DataType::getDigits(long num) {


	unsigned count = 0;
	while (num >= pow(10, double(count))) count++;

	return count;




}


vector<char> DataType::dtoVchar(double num) {

	int count;
	int digit;
	int intCount;
	int floatCount =0;
	long long intNum, floatNum = 0;


	int temp;

	vTemp.clear();

	if (num < 0) {
		vTemp.push_back('-');
		num *= -1;
	}

	intNum = num;

	intCount = getDigits(intNum);

	count = getDigits(intNum);

	while (count > 0)
	{


		long divider = pow(double(10), double(count - 1));

			digit = intNum / divider;

		intNum %= divider;
		vTemp.push_back(digit + 48);
		count--;

	}


	if (intCount == 0)
		vTemp.push_back('0');


	intNum = (long long)num;
	num -= intNum;


	if (num != 0)
		vTemp.push_back('.');
	while (num !=0 && floatCount ++ < 9)
	{
		num *= 10;
		vTemp.push_back(long(num) + 48);
		temp = long(num);
		num -= temp;


	}


	if (floatNum != 1)
		count = getDigits(floatNum);

	if (count != 0)
		vTemp.push_back('.');

	while (count > 0)
	{

		long divider = pow(double(10), double(count - 1));
		digit = floatNum / divider;
		floatNum %= divider;
		vTemp.push_back(digit + 48);
		count--;



	}
	return vTemp;

}

