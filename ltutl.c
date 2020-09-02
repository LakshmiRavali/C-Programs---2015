#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void low2upp(char *);
struct test {
	char *input,output[50];
} testDB[5] = {{"hello world","HELLO WORLD"},
				{"HellO","hELLo"},
                {"aBc @@@ 123 xYz","AbC @@@ 123XyZ"},
                {"123","123"},
            };
void testCases()
{
	int i,c,l;
	for( i=0; i<5; i++) 
	{
		low2upp(testDB[i].input);
		if(strcmp(testDB[i].input,testDB[i].output))
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
void low2upp(char *str)
{
	int i,j;
	char c;
	for(i=0;str[i]!='\0';i++)
	{
		printf("%c",(int)str[i]-32);
		if(str[i]<65||str[i]>127)
			continue;
		else if(str[i]>65&&str[i]<97)
			c=(int)str[i]+32;
		else if(str[i]>=97&&str[i]<127)
			c=((int)str[i]-32);
			str[i]=c;
	}
}