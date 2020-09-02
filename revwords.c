#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int compare(char *,char *);
void revwords(char *);
void dynamic(char *,int,char *);
int firstposition(char *,int);
int lastposition(char *,int);
void testCases();
struct test {
	char input1[25];
	int l1,l2;
	char output[25];
} testDB[16]={{{" hai  madam"},11,11," madam  hai"},
{{"### ravali  "},12,12,"ravali ###  "},
{{"hello  ++++"},11,11,"++++  hello"},		
{{"mmmm"},4,4,"mmmm"},
{"hello this",10,10,"this hello"},
{"@@ @@ to",8,8,"to @@ @@"},
{"hai this is rossy",17,17,"rossy is this hai"},
{"ramu is a good   boy    ",23,23,"boy good a is   ramu    "},
{"   hai  this is ravali  ",24,24,"   ravali  is this hai  "},
{"welcome  ravali  ",17,17,"ravali  welcome  "},
{"  welcome to   gvp",18,18,"  gvp to   welcome"},
{"   lakshmi  ravali   ",21,21,"   ravali  lakshmi   "},
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
	for(i=0;i<12;i++)
	{
		a=(char *)malloc(sizeof(int)*testDB[i].l1);
		dynamic(a,i,testDB[i].input1);
		revwords(a);
		b=(char *)malloc(sizeof(int)*testDB[i].l2);
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
int firstposition(char *a,int i)
{
	int c=0;
	while(c<1)
	{
		if(a[i]!=' ')
			c++;
		i++;
	}
	return i-1;
}
int lastposition(char *a,int i)
{
	int c=0;
	while(a[i]!='\0')
	i++;
	i--;
	while(c<2)
	{
		if(a[i]==' '&&c==0)
			i--;
		else if(a[i]!=' ')
		{
			c=1;
			i--;
		}
		else if(a[i]==' '&&c==1)
		{
			i++;
			c=2;
		}
	}
	return i;
}
void revwords(char *a)
{
	int i=0,j=0,k,c=0;
	char temp;
	i=firstposition(a,i);
	j=lastposition(a,j);
	while(i<j)
	{
		if(a[i]!=' '&&a[j]!=' ')
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j++;
		}
		else if(a[i]==' '&&a[j]=='\0')
		{
			i=firstposition(a,i);
			j=lastposition(a,j);
		}
		else if(a[i]==' '&&a[j]==' ')
		{
			i=firstposition(a,i);
			j=lastposition(a,j);
		}
		else if(a[i]==' '&&a[j]!=' ')
		{
			temp=a[j];
			for(k=j;k>i;k--)
			{
				a[k]=a[k-1];
			}
			a[i]=temp;
			i++;
			j++;
		}
		else if(a[j]==' '&&a[i]!=' ')
		{
			temp=a[i];
			for(k=i;k<j-1;k++)
				a[k]=a[k+1];
			a[k]=temp;
		}
	}
}