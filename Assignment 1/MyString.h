#pragma once
#include<iostream>
#include<cstring>


using namespace std;

class MyString
{
	char* _str;
	int _length;

public:
	MyString() { _str = NULL; _length = 0; }	//#1 Default constructor	
	MyString(const char* str)			//#2 Parameteric constructor
	{
		this->_length = strlen(str);
		this->_str = (char*) str;
	}
	MyString(const MyString& myString)			//#6 Copy constructor
	{
		this->_length = strlen(myString._str);
		this->_str = new char[_length + 1];
		this->_str = myString._str;
	}
	~MyString()									//#3 Destructor
	{
	}
	int getLength() { return _length; }			//#5 getLength()
	void setStr(const char* str) { _str = (char*)str; _length = strlen(str); }		//#14 setStr()
	char* getStr() { return _str; }
	void display();								//#4 display()
	const MyString operator = (const MyString& myString);	//#7 Assignment Operator
	friend ostream& operator<<(ostream& out, const MyString& myString);	//#8 stream insertion
	MyString operator+(const MyString& myString) const;		//#9 operator +
	bool operator==(const MyString& myString) const;		//#10 operator ==
	bool operator<(const MyString& myString) const;			//#11 operator <
	bool operator>(const MyString& myString) const;
	bool operator<=(const MyString& myString) const;		//#12 operatot <=
	bool operator>=(const MyString& myString) const;
	const MyString& operator+=(const MyString& myString);	//#13 operator +=
	operator int() const;									//#15 int conversion
	operator char* () const;								//#16 char* conversion
	MyString& operator++();									//#17 operatopr ++
	friend istream& operator>>(istream& in, MyString& myString);	//#18 extraction operator
};


