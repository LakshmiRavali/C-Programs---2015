#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
int length(char[]);
struct test {
	char input[50];
	int k;
} testDB[5] = {{"hello world",11},
				{"hello",5},
                {"",0},
                {"123@@@",6},
            };
void testCases()
{
	int i,l;
	for( i=0; i<5; i++) 
	{
		l=length(testDB[i].input);
	if(l==testDB[i].k)
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
int length(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}