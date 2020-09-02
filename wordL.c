#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
int word(char[]);
struct test {
	char input[50];
	char output[50];
} testDB[7] = {{"hello world","world"},
				{"hello","hello"},
                {"welcome to the world","world"},
                {"123","123"},
                {"",""},
				{"hai ravali","ravali"},
				{"@@@ hai ABC","ABC"},
            };
void testCases()
{
	int i,c,j=0,k=0,r=0;
	for( i=0; i<7; i++) 
	{
		c=word(testDB[i].input);
		for(k=c+1;testDB[i].input[k]!='\0';k++,j++)
		if(testDB[i].input[k]==testDB[i].output[j]) 
			r=1;
		if(r==1)
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
int word(char str[])
{
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
			j=i;
		i++;
	}
	return j;
}