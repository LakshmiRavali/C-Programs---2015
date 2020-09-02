#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
int convow(char[]);
int length(char[]);
struct test {
	char input[50];
	int v,c;
} testDB[5] = {{"hello world",3,7},
				{"hello",2,3},
                {"abc @@@ 123 xyz",1,5},
                {"123",0,0},
                {"",0,0},
            };
void testCases()
{
	int i,c,l;
	for( i=0; i<5; i++) 
	{
		c=convow(testDB[i].input);
		l=length(testDB[i].input);
		if(testDB[i].v==c&&testDB[i].c==(l-c))
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
	int i=0,j=0;
	while(str[i]!='\0')
	{
		i++;
		if(str[i]==' '||(int)str[i]<65||(int)str[i]>127)
			continue;
		j++;
	}
	if(j==0)
		return 0;
	else
	return j+1;
} 
int convow(char str[])
{
	int i,c=0;
	for(i=0;i<str[i]!='\0';i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			c++;
	}
	return c;
}