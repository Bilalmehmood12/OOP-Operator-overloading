#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
	public:
		char findTheDifference(string s, string t) {
			int temp = 0;
			char res;
			for (int i = 0; s[i]!='\0';i++)
			{
				for (int j = 0; t[j]!='\0'; j++)
				{
					if((s[i]==t[j]))
					{
						temp++;
					}
				}
				if (temp == 0)
				{
					res = s[i];
					break;
				}
			}
			return res;
		}
};
int main()
{
	string s, t;
	getline(cin, s);
	getline(cin, t); 
	Solution solution;
	cout<< solution.findTheDifference(s, t);
	return 0;
}
