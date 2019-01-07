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

#pragma endregion

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
		length++;//incriment the length counter
	}
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
	int middle = (start + end) / 2;//define middle point
	for (i = 0; i <= middle; i++)//run to the middle of the array
	{
		temp = arr[start + i];
		arr[start + i] = arr[end - i];
		arr[end - i] = temp;
		//switch the opposing array indexes in relation to start and end points
	}
}



/***************************************************************************************
Function name:
Input:
Output:
The function operation:
****************************************************************************************/