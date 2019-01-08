#include <stdio.h>
/************************
Ilay Tzuberi
211873286
83-120-05
*************************/

/***************************************************************************************
Function name: DiffersInNChars
Input: two (2) strings and an error rate n
Output: None
The function operation: print "yes" if the 2 strings have n or lower differences between them
						print "no" if the 2 strings have more than n differences between them
****************************************************************************************/
void DiffersInNChars(char s1[], char s2[], int n)
{
	char *p1, *p2;//make pointers
	p1 = &s1[0];//p1 is the start of the first array
	p2 = &s2[0];//p2 is the start of the second array
	if (*p1 == '\0' && *p2 == '\0' && n >= 0)//if the arrays are empty and n >=0 
	{
		printf("yes\n");//print yes
		return;//come out of the recursion
	}
	else if (*p1 != *p2 && n==0)//if the arrays arnt the same and we have run out of n
	{
		printf("no\n");//print no
		return;//come out of recursion
	}
	else
	{
		n -= (*p1 != *p2);//if the strings arnt equal decrement n by 1
		if (*p1 != '\0')//if p1 isnt the end of the s1
			++p1;//advance him
		if (*p2 != '\0')//if p2 isnt the end of the s2
			++p2;//advance him
		DiffersInNChars(p1, p2, n);
	}
}