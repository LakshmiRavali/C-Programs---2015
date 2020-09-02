#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char *substring(char[],int,int);
struct test {
	char input[50];
	int i,j;
	char output[50];
} testDB[5] = {{"hello world",7,11,"world"},
				{"hello",2,7,"ello"},
                {"welcome to the world",22,24,""},
                {"hello",13,15,""},
            };
void testCases()
{
	int i,j=0,r=0;
	char *p;
	for( i=0; i<4; i++) 
	{
		p=substring(testDB[i].input,testDB[i].i,testDB[i].j);
		for(j=0;testDB[i].output[j]!='\0'||p[j]!='\0';j++)
		if(p[j]==testDB[i].output[j]) 
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
char *substring(char str[],int i,int j)
{
	char *s;
	int t,k=0;
	if(i>j)
	{
		t=i;
		i=j;
		j=t;
	}
	s=(char *)(calloc((j-i),sizeof(int)));
	if(i<0)
		i=1;
	for(t=i-1;t<j&&str[t]!='\0';t++,k++)
		s[k]=str[t];
	s[k]='\0';
	return s;
}