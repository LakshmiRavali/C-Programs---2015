#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
int count(char[]);
struct test {
	char input[50];
	int k;
} testDB[5] = {{"hello world",2},
				{"hello",1},
                {"",0},
                {"abc def ghj",3},
            };
void testCases()
{
	int i,l;
	for( i=0; i<5; i++) 
	{
		l=count(testDB[i].input);
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
int count(char str[])
{
	int i=0,c=1;
	for(i=0;str[i]!='\0';i++)
		if(str[i]==' ')
			c++;
	if(i==0)
		return 0;
	else
		return c;
}