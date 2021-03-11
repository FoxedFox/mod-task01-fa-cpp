#include "fun.h"
unsigned int faStr1(const char* str)
{
	int i, count, pos, sym=0;
	i = 0;
	count = 0;
	pos = 0;
	while (str[i] != '\0')
	{
		if (pos == 0 && str[i] != 32)
		{
			if ( str[i] < 48 || str[i] > 57) 
			sym= 1;
			pos = 1;
		}
		else if (pos == 1 && str[i] == 32)
		{
			if (sym== 1) 
			count++;
			sym= 0;
			pos = 0;
		}
		else if (pos == 1 && str[i] != 32 && sym== 1)
		{
			if (str[i] >= 48 && str[i] <= 57) 
				sym = 0;
		}
		i++;
	}
	if (pos == 1 && sym== 1) 
		count++;
	return count;
}

unsigned int faStr2(const char* str)
{
	int i, count, pos, sym = 0;
	i = 0;
	count = 0;
	pos = 0;
	while (str[i] != '\0')
	{
		if (pos == 0 && str[i] >= 65 && str[i] <= 90)
		{
			pos = 1;
			sym = 1;
		}
		else if (pos == 1 && str[i] == 32)
		{
			if (sym== 1) count++;
			sym= 0;
			pos = 0;
		}
		else if (pos == 1 && str[i] != 32 &&sym== 1)
		{
			if (str[i] >= 65 && str[i] <= 90)
				sym= 0;
			if (str[i] < 65 ||str[i] > 122 )
				sym= 0;
		}
		i++;
	}
	if (pos == 1 &&sym== 1) count++;
	return count;
}

unsigned int faStr3(const char* str)
{
	int length = 0;
	int i, count, pos, sym = 0;
	i = 0;
	count = 0;
	pos = 0;
	 int mid_length = 0;
	float sum = 0;
	while (str[i] != '\0')
	{
		if (pos == 0 && str[i] != 32)
		{
			count++;
			pos = 1;
			length++;
		}
		else if (pos == 1 && str[i] == 32)
		{
			sum = sum + length;
			pos = 0;
			length = 0;
		}
		else if (pos == 1 && str[i] != 32) 
			length++;
		i++;
	}
	if (pos == 1) sum = sum + length;
	sum = sum / (float)count;
	mid_length = sum;
	if (sum - (float)mid_length >= 0.5) 
		mid_length++;
	return mid_length;
}
