#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int compare(char *,char *);
void spaces(char *);
void dynamic(char *,int,char *);
void testCases();
struct test {
	char input1[20];
	int l1,l2;
	char output[20];
} testDB[16]={{{"hai madam"},9,8,"haimadam"},
{{"###  ravali"},10,9,"###ravali"},
{{"hello   ++++"},12,9,"hello++++"},		
{{"mmmm"},4,4,"mmmm"},
{"hello this  ",13,9,"hellothis"},
{"@@  @@ to",9,6,"@@@@to"},
{"cse",3,3,"cse"},
{"this is",7,6,"thisis"},
{"par   ty hai",12,8,"partyhai"},
{"   ravali   ",12,6,"ravali"},
{"  33rrr  56",11,6,"33rr56"},
{"{{{   }}}",9,6,"{{{}}}"},
{"/* */ --",8,6,"/**/--"},
{"     ",5,0,""},
{"\n 23  ",7,4,"\n23"},
{"$$$  %%  ",9,5,"$$$%%"},
};
void dynamic(char *a,int i,char *input1)
{
	int j=0;
		while(input1[j]!='\0')
		{
			a[j]=input1[j];
			j++;
		}
		a[j]='\0';
}
void testCases()
{
	char *a,*b;
	int i,c=1;
	for(i=0;i<15;i++)
	{
		a=(char *)malloc(sizeof(int)*testDB[i].l1);
		dynamic(a,i,testDB[i].input1);
		spaces(a);
		b=(char *)malloc(sizeof(int)*testDB[i].l2);
		dynamic(b,i,testDB[i].output);
	if(compare(a,b)==0)
		printf("\npassed");
	else
		printf("\nfailed");
	free(a);
	free(b);
	}
}
int compare(char *a,char *b)
{
	int i=0,j=0,c=0;
	while(a[i]!='\0'||b[j]!='\0')
	{
		if(a[i]!=b[j])
		{
			c=1;
			break;
		}
		i++;
		j++;
		return c;
	}
}
void main()
{
	testCases();
	getch();
}
void spaces(char *a)
{
	int i=0,j=0,c=0;
	while(a[i]!='\0')
	{
		if(a[i]==' ')
		{
			if(j==1)
			{
				c=0;
				j=0;
			}
			c++;
		}
		else if(c!=0)
		{
			a[i-c]=a[i];
			c=1;
			j=1;
		}
		i++;
	}
	a[i]='\0';
}