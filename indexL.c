#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char index(char[],int);
struct test {
	char input[50],output;
	int k;
} testDB[7] = {{"hello world",'r',3},
				{"hello",' ',6},
                {"hello",' ',-2},
                {"123",'3',1},
{"hai welcome to GVP",'G',3},
{"lakshmi ravali",'r',6},
            };
void testCases()
{
	int i;
	char c;
	for( i=0; i<7; i++) 
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
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if(i>=k-1)
			j++;
		i++;
	}
	if(k>i||k<0)
		return ' ';
	else 
	return str[j-1];
}