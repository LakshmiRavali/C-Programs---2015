#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int compare(char *,char *);
char *rev(char *);
void testCases();
struct test {
	char input1[20];
	int l;
	char output[20];
} testDB[10]={{{"madam"},5,"madam"},
{{"ravali"},6,"ilavar"},
{{"hello"},5,"olleh"},		
{{"mmmm"},4,"mmmm"},
{"hello this",11,"siht olleh"},
{"welcome to",10,"ot emoclew"},
{"cse",3,"esc"},
{"this is",7,"si siht"},
{"party hai",9,"iah ytrap"}
};
void testCases()
{
	char *p,*a,*b;
	int i,j=0,c=1;
	for(i=0;i<10;i++)
	{
		j=0;
		a=(char *)malloc(sizeof(int)*testDB[i].l);
		while(testDB[i].input1[j]!='\0')
		{
			a[j]=testDB[i].input1[j];
			j++;
		}
		a[j]='\0';
		p=rev(a);
		b=(char *)malloc(sizeof(int)*testDB[i].l);
		j=0;
		while(testDB[i].output[j]!='\0')
		{
			b[j]=testDB[i].output[j];
			j++;
		}
		b[j]='\0';
	if(compare(p,b)==0)
		printf("\npassed");
	else
		printf("\nfailed");
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
char *rev(char *a)
{
	int i=0,j=0;
	char temp;
	while(a[j]!='\0')
		j++;
	while(i<j)
	{
		j--;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
	}
	return a;
}