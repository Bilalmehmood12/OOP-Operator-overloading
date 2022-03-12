#pragma once
#include<cstring>
int sum(char* str)
{

	int length = strlen(str), result = 0;
	for (int i = 0;i < length;i++)
	{
		result += (int)str[i];
	}
	return result;
}