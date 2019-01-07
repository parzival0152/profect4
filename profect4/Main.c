#include <stdio.h>

int main()
{
	char str[17] = "word,list,sample";
	printStrings(str);
	int a = ReverseStrings(str);
	printStrings(str);
	printf("%d\n", a);
	system("pause");
	return 0;
}
