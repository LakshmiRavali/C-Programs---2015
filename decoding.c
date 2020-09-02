//removing dublicates case sensitive 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void alphanum(char *);
int count(char *,int,int);
struct test {
	char input[150],output[50];
} testDB[15] = {{"aaaabbbbccc","a-4,b-4,c-3"},
				{"1111111111","1-10"},
                {"rrraaavv","r-3,a-3,v-2"},
				{"abbbbccd","a-1,b-4,c-2,d-1"},
				{"11111111111222","1-11,2-3"},
				{"@@@@","@-4"},
				{"abc","a-1,b-1,c-1"},
				{"aaaaaaaaaabbbb","a-10,b-4"},
				{"aaaaaaaaaacaaaaaaaaaaaaaaaaa","a-10,c-1,a-17"},
				{"***///","*-3,/-3"},
				{"@@@AAAA","@-3,A-4"},
				{"112233aaa","1-2,2-2,3-2,a-3"},
				{"++++111aa","+-4,1-3,a-2"},
{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","a-110"},
{"AaaaaBcCCC","A-1,a-4,B-1,c-1,C-3"},
            };
void testCases()
{
	int i;
	for( i=0; i<15; i++)	
	{
		alphanum(testDB[i].input);
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
int count(char *str,int c,int l)
{
	int k,i=-1,p=5;
	char *a;
	a=(char *)malloc((sizeof(int)*5));
	while(c!=0)
		{
		if(i>=p)
		{
			p=p+5;
			realloc(a,p);
		}
			k=c%10;
			c=c/10;
			i++;
			a[i]=(char)k+48;
		}
		k=i;
		l++;
		str[l]='-';
	while(i>=0)
	{
		l++;
		str[l]=a[i];
		i--;
	}
	return l;
}
void alphanum(char *str)
{
	int i=0,j=1,c=1,k,r;
	char a[20];
	while(str[j]!='\0')
	{
		if(str[i]==str[j])
		{
			j++;
			c++;
		}
		else
		{
			if(c>=10)
			{
				i=count(str,c,i);
				i++;
				str[i]=',';
			}
			else
			{
				if(c==1||c==2||c==3)
				{
					if(c==1)
						r=3;
					else if(c==3)
						r=1;
					else 
						r=2;
					k=i;
					while(str[k]!='\0')
						k++;
					str[k+r]='\0';
					k--;
					while(k>i)
					{
						str[k+r]=str[k];
						k--;
					}
					i++;
					str[i]='-';
					i++;
					str[i]=(char)c+48;
					i++;
					str[i]=',';
					j=j+r;
				}
				else if(c!=0)
				{
				i++;
				str[i]='-';
				i++;
				str[i]=(char)c+48;
				i++;
				str[i]=',';
				}
				i++;
				str[i]=str[j];
			}
			c=0;
		}
	}
	if(c>=10)
	{
		i=count(str,c,i);
		str[i+1]='\0';
	}
	else
	{
		str[i+1]='-';
		str[i+2]=(char)c+48;
		str[i+3]='\0';
	}
	i=0;
}