#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void rvow(char *);
struct test {
	char input[50],output[50];
} testDB[8] = {{"hello world","hll wrld"},
				{"HellO","Hll"},
                {"abc @@@ 123 xyz","bc @@@ 123 xyz"},
                {"123","123"},
				{"ravali","rvl"},
				{"@@@@","@@@@"},
				{"welcome","wlcm"},
				{"How R U","Hw R "},
            };
void testCases()
{
	int i,c,l;
	for( i=0; i<8; i++) 
	{
		rvow(testDB[i].input);
		if(strcmp(testDB[i].input,testDB[i].output)==0)
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
void rvow(char *str)
{
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		{
			j=i+1;
			while(str[j]!='\0')
			{
				str[j-1]=str[j];
				j++;
			}
			str[j-1]='\0';
		}
		i++;
	}
}