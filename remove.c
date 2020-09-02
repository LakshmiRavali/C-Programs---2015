//case in sensitive
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void removadj(char *);
struct test {
	char input[50],output[50];
} testDB[14] = {{"aaaabbbbccc","abc"},
				{"aabbaabb","abab"},
                {"rrraaavv","rav"},
                {"123","123"},
				{"ravali","ravali"},
				{"@@@@","@"},
				{"Aa","A"},
{"aaaABbbbCcccD","aBCD"},
{"@@@AAAAa","@A"},
{"112233aaa","123a"},
{"****////","*/"},
{"++++111aaA","+1a"},
{"A a","A a"},
{"ab ba ","ab ba "},
            };
void testCases()
{
	int i,c,l;
	char *a;
	for( i=0; i<14; i++) 
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
	int i=0,j=1;
	while(str[j]!='\0')
	{
		if(str[i]==str[j])
			j++;
		else if(str[j]==str[i]-32||str[j]==str[i]+32)
		{
			if(str[i]>='A'||str[i]<='z')
			j++;
			else
			{
				i++;
				str[i]=str[j];
			}
		}
		else
		{
			i++;
			str[i]=str[j];
		}
	}
	str[i+1]='\0';
}