#include "MyString.h"
#include"sum.h"

const MyString MyString::operator = (const MyString& myString)	//#7 Assignment Operator
{
	this->_length = myString._length;
	this->_str = myString._str;
	return *this;
}
ostream& operator<<(ostream& out, const MyString& myString)
{
	out << myString._str;
	return out;
}
istream& operator>>(istream& in, MyString& myString)
{
	char ch[100];
	in.getline(ch, 100);
	myString.setStr(ch);
	return in;
}
void MyString::display()
{
	std::cout << this->_str;
}
MyString MyString::operator+(const MyString& myString) const
{
	int size1 = this->_length;
	int size2 = myString._length;
	int size =  size1+ size2 + 1;
	char* ptr = new char[size];
	for (int i = 0;i < this->_length;i++)
	{
		*(ptr+i) = this->_str[i];				//getting data from firsr operand
	}
	for (int i = 0; i < myString._length;i++)
	{
		*(ptr + size1 + i) = myString._str[i];	//from sencond operand
	}
	*(ptr + size - 1) = '\0';					//terminating array or pointor
	MyString newMyString(ptr);					
	return newMyString;							//returning concatinated result
}
bool MyString::operator==(const MyString& myString) const {
	if (sum(this->_str) == sum(myString._str))	//checking if all the charactors are same
	{
		return true;
	}
	return false;
}
bool MyString::operator<(const MyString& myString) const
{
	if (sum(this->_str) < sum(myString._str))	//checking which sum is less
	{
		return true;
	}
	return false;
}
bool MyString::operator>(const MyString& myString) const
{
	if (sum(this->_str) > sum(myString._str))
	{
		return true;
	}
	return false;
}
bool MyString::operator<=(const MyString& myString) const
{
	if (sum(this->_str) <= sum(myString._str))	//checking which sum is less or equal
	{
		return true;
	}
	return false;
}
bool MyString::operator>=(const MyString& myString) const
{
	if (sum(this->_str) >= sum(myString._str))
	{
		return true;
	}
	return false;
}
const MyString& MyString::operator+=(const MyString& myString) 
{
	*this = *this + myString;					//calling operator +
	return *this;								//returning result of += operator
}
MyString::operator int() const 
{
	int result = 0;
	for (int i = 0;i < this->_length;i++)
	{
		if (((int)this->_str[i] >= 48) && ((int)this->_str[i] <= 57))	//checking if digit is a no. or not
		{
			result = result + ((int)this->_str[i] - 48);
			result *= 10;									//multiplying by 10 for next iteration 70 + 5
		}
		else
		{
			return 0;							//even a single alphabet result in 0 mean not a no.
		}
	}
	result /= 10;
	return result;
}
MyString::operator char*() const 
{
	return this->_str;					//returning char type pointer
}

MyString& MyString::operator++()
{
	int result;
	char* ptr = new char[this->_length+1];
	for (int i = 0;i < this->_length;i++)
	{
		if (((int)this->_str[i] >= 97) && ((int)this->_str[i] <= 122))	//checking for lowercase alphabet
		{
			result = (int)this->_str[i] - 32;							//converting lowercase to uppercase alphabet
			ptr[i] = (char)result;										//adding to array
		}
		else
			ptr[i] = this->_str[i];										//keeping other characters as it is
	}
	ptr[this->_length] = '\0';											//terminating pointer
	MyString newMyString(ptr);
	return newMyString;													//returning new MyString obj having uppercase alphabet
}