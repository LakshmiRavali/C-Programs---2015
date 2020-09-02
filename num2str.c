#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int compare(char *,char *);
char *spaces(int *);
void dynamic(char *,int,char *);
int move(char *,int);
void testCases();
struct test {
	int input;
	int l;
	char output[20];
} testDB[10]={{1234,4,"1234"},
{234,3,"234"},
{34,2,"34"},
{-123,4,"-123"},
{-45,3,"-45"},
{89,2,"89"},
{23456,5,"23456"},
{1000,4,"1000"},
{0,1,"0"},
{-1,2,"-1"}};
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
	for(i=0;i<10;i++)
	{
		a=spaces(testDB[i].input);
		b=(char *)malloc(sizeof(int)*testDB[i].l);
		dynamic(b,i,testDB[i].output);
	if(compare(a,b)==0)
		printf("\npassed");
	else
		printf("\nfailed");
	//free(a);
	//free(b);
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
int move(char *r,int j)
{
	int k=0;
	for(k=j;k>0;k--)
			r[k]=r[k-1];
	return k;
}
char *spaces(int a)
{
	int i=0,j=0,k=0,o;
	char *r;
	r=(char *)malloc(sizeof(int)*20);
	o=a;
	if(a==0)
	{
		r[0]='0';
		j++;
	}
	else
	{
	while(a!=0)
	{
		i=a%10;
		if(i<0)
			i=-(i);
		a=a/10;
		if(j==0)
		r[j]=(char)i+48;
		if(j!=0)
		{
		k=move(r,j);
		r[k]=(char)i+48;
		}
		j++;
	}
	}
	if(o<0)
	{
		k=move(r,j);
		r[k]='-';
		j++;
	}
	r[j]='\0';
	return r;
}