#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char index(char[],int);
struct test {
	char input[50],output;
	int k;
} testDB[5] = {{"hello world",'l',3},
				{"hello",' ',6},
                {"hello",' ',-2},
                {"123",'1',1},
            };
void testCases()
{
	int i;
	char c;
	for( i=0; i<4; i++) 
	{
		c=index(testDB[i].input,testDB[i].k);
		if(c==testDB[i].output)
			printf("PASSED\n"); 
		else 
			printf("FAILED\n");
	}
	
}
void main()
{
	testCases();
	getch();
}
char index(char str[],int k)
{
	if(k<0)
		return ' ';
	else if(str[k-1]=='\0')
		return ' ';
	else
	return str[k-1];
}