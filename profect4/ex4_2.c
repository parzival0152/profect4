#include <stdio.h>
/************************
Ilay Tzuberi
211873286
83-120-05
*************************/

void DiffersInNChars(char s1[], char s2[], int n)
{
	char *p1, *p2;
	p1 = &s1[0];
	p2 = &s2[0];
	if (*p1 != *p2 && n == 0)
	{
		printf("no\n");
		return;
	}
	else if (*p1 != *p2 && n != 0)
	{
		DiffersInNChars(++p1, ++p2, n - 1);
		return;
	}

}