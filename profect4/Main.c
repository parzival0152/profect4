#include <stdio.h>

int main()
{
	char str[] = "1";
	char * p;
	p = &str[0];
	printf("%c\n",*p);
	printf("%c\n", *(++p));
	printf("%c\n", *(++p));
	system("pause");
	return 0;
}
