#include <stdio.h>
/************************
Ilay Tzuberi
211873286
83-120-05
*************************/

//func decleration super block for easy viewing
#pragma region func decleration 

int ReverseStrings(char buffer[]);
void printStrings(const char str[]);
void reverseArrayAtLocation(char arr[], int start, int end);
void ReverseStringsManager(char str[]);

#pragma endregion

/***************************************************************************************
Function name: ReverseStrings
Input: comma seperated strings to swap places
Output:0 if succsessfull -1 if bad input
The function operation: switches each word around then flip the whole array
						to get the desired output
****************************************************************************************/
int ReverseStrings(char buffer[])
{
	int i,issmall, islarge, valid;//int as bool values
	int start = 0, length = 0;//counters and flags set to 0
	for (i = 0; buffer[i] != '\0'; i++)
	{//loop over the array until you get to the end
		issmall = 'a' <= buffer[i] && buffer[i] <= 'z';//is the char a small letter
		islarge = 'A' <= buffer[i] && buffer[i] <= 'Z';//is the char a large letter
		valid = issmall || islarge || buffer[i] == ',';//make them one bool

		if (!valid)//if the array contains a bad char
			return -1;//end the func and return -1
		if (buffer[i] == ',' && i != 0)//if you encounter a ','
		{
			reverseArrayAtLocation(buffer, start, i - 1);//reverse the entire word infront of it
			start = i + 1;//set the start point of the next word as the char after the ','
		}
		else if (buffer[i] == ',' && i == 0)//is you get an empty word at the start of the array
			start = 1;//move the start point up to 1
		length++;//incriment the length counter
	}
	reverseArrayAtLocation(buffer, start, length - 1);
	reverseArrayAtLocation(buffer, 0, length - 1);
	return 0;
}

/***************************************************************************************
Function name: printStrings
Input: constant char array
Output: None
The function operation: print the string array
****************************************************************************************/
void printStrings(const char str[])
{
	int i;//define itiratior
	for (i = 0; str[i]!='\0'; i++)
	{//loop untill you get to the end of the string
		printf("%c",str[i]);//print char
	}
	printf("\n");//go down a line
}

/***************************************************************************************
Function name: reverseArrayAtLocation
Input: array of chars, index of start and end locations
Output: None (array changes)
The function operation: changes the array in between two (2) given points
****************************************************************************************/
void reverseArrayAtLocation(char arr[], int start, int end)
{
	int i;//define itiratior
	char temp;//temp char 
	int middle = (end - start + 1) / 2;//find the middle value
	for (i = 0; i < middle; i++)//run fir half the given range
	{
		temp = arr[start + i];
		arr[start + i] = arr[end - i];
		arr[end - i] = temp;
		//switch the opposing array places by relation to the middle
	}
}

/***************************************************************************************
Function name: ReverseStringsManager
Input: comma seperated strings to swap places
Output: None
The function operation: manage the inputed string array
****************************************************************************************/
void ReverseStringsManager(char str[])
{
	printf("The word list: ");//intro
	printStrings((const char(*)[])str);//print the given string while making it into a const array
	int a = ReverseStrings(str);//reverse the string and get the returned value
	if (a == -1)
	{//is the input is bad
		printf("The list is illegal!\n");//print that its wrong
		return;//and exit
	}
	//if not
	printf("Reverse: ");//print the "Reverse: " part 
	printStrings((const char(*)[])str);//print the reversed string while making it into a const array
}



/***************************************************************************************
Function name:
Input:
Output:
The function operation:
****************************************************************************************/