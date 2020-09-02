//removing dublicates case in-sensitive 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void alphanum(char *);
int count(char *,int,int);
struct test {
	char input[50],output[50];
} testDB[14] = {{"aAaaAbbbBccc","a5b4c3"},
				{"aaAaaAaaAa","a10"},
                {"rrRaAaVv","r3a3V2"},
				{"abBbbccD","a1b4c2D1"},
				{"aBbbbbbbbbbbcd","a1B11c1d1"},
				{"@@@@","@4"},
				{"abc","a1b1c1"},
				{"aaaaaaaaaabbbb","a10b4"},
				{"aaaaaaaaaACaaaaaaaaaaaaaaaaa","a10C1a17"},
				{"***///","*3/3"},
				{"@@@AAAA","@3A4"},
				{"++++111aa","+413a2"},
				{"AaaaaBcCCC","A5B1c4"},
            };
void testCases()
{
	int i;
	for( i=0; i<14; i++)	
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
	int i=0,j=1,c=1,k;
	char a[20];
	while(str[j]!='\0')
	{
		if(str[i]==str[j]||str[i]==(str[j]-32)||str[i]==(str[j]+32)||str[j]==(str[i]-32)||str[j]==(str[i]+32))
		{
			j++;
			c++;
		}
		else
		{
			if(c>=10)
			{
				i=count(str,c,i);
			}
			else
			{
				if(c==1)  //no dublicates are present int the given string
				{
					k=i;
					while(str[k]!='\0')
						k++;
					str[k]='\0';
					k--;
					while(k>i)
					{
						str[k+1]=str[k];
						k--;
					}
					i++;
					str[i]=(char)c+48;
					j++;
				}
				else if(c!=0)   //dublicates are present 
				{
				i++;
				str[i]=(char)c+48;
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
	str[i+1]=(char)c+48;
	str[i+2]='\0';
	}
}