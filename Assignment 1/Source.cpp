#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	//#1 & #2 constructor
	MyString ms1("One");
	MyString ms2("Two");
	MyString ms3("Three");
	MyString ms4;

	//#7 Assignment = & #9 concatination + operator overloading
	ms4 = ms1 + ms2 + ms3;

	//#8 Stream insertion operator << overloading
	cout << ms1 << endl; // should display: One
	cout << ms2 << endl; // should display: Two
	cout << ms3 << endl; // should display: Three
	cout << ms4 << endl;

	//#5 getLength()
	cout << "The length of \"" <<ms3<<"\" is " << ms3.getLength() << endl;

	MyString s1("abc");
	MyString s2("ABC");
	MyString s3("az");
	MyString s4("abc");

	//#10 comparing == operator overloading
	cout << (s1 == s2) << endl; // should display: 0 (false)
	cout << (s4 == s1) << endl; // should display: 1 (true)
	cout << (s4 == s4) << endl; // should display: 1 (true)

	//#11 less than < operator overloading
	cout << (s1 < s2) << endl; // should display: 0 (false)
	cout << (s2 < s1) << endl; // should display: 1 (true)
	cout << (s1 < s3) << endl; // should display: 1 (true)

	//#12 less than equal to <= operator overloading
	cout << (s1 <= s3) << endl; // should display: 1 (true)
	cout << (s1 <= s4) << endl; // should display: 1 (true)
	cout << (s2 <= s2) << endl; // should display: 1 (true)
	
	//#13 += assignment arithmatic operator overloading
	ms1 += ms2 += ms3;

	//#4 display()
	ms1.display(); // should display: OneTwoThree
	cout << endl;
	ms2.display(); // should display: TwoThree
	cout << endl;
	ms3.display(); // should display: Three
	cout << endl;

	//#14 setStr()
	ms3.setStr("Hello World");
	cout << ms3.getLength() << endl;
	
	MyString s01("7504");
	MyString s02("56 abc def");
	//#15 Conversion int
	int i1 = s01; // using the conversion operator int
	int i2 = s02; // using the conversion operator int
	cout << i1 << endl; // should display: 7504
	cout << i2 << endl;

	//#16 coversion char*
	cout << s1 << endl; // should display: Hello World
	char* cp = s1; // using the conversion operator char*
	cout << cp << endl;
	ms3.setStr("One !#^; 123 two");

	//#17 pre-increment operator
	s2 = ++ms3;
	cout << ms3 << endl; // should display: ONE !#^; 123 TWO
	cout << s2 << endl; // should display: ONE !#^; 123 TWO
	MyString myString;
	s1.setStr("Hello");
	cout << s1 << endl; // should display: Hello
	cout << "Enter a MyString: ";
	cin >> myString; // Suppose the user enters: Pakistan Zindabad!!
	cout << myString << endl; // should display: Pakistan Zindabad!!
	return 0;
}