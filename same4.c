//case in sensitive
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
char* alphanum(char *,char *);
struct test {
	char input1[50],input2[50],output[50];
} testDB[14] = {{"rAma","mara","rAma"},
				{"marse","Rama","mar"},
                {"Abca","aebfc","Abc"},
				{"aaaabbb","aab","aab"},
				{"Rama","maars","Rama"},
				{"Ravali","ravali","Ravali"},
				{"","",""},
				{"ravali","ilavar","ravali"},
{"AbCdE","ABCDE","AbCdE"},
{"abcde","fghij",""},
};
void testCases()
{
	int i,j=0;
	char *c;
	for( i=0; i<10; i++)	
	{
		c=alphanum(testDB[i].input1,testDB[i].input2);
		if(strcmp(c,testDB[i].output)==0)
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
char* alphanum(char *a,char *b)
{
	 char *p,*q,*r;
	 int *v,k=0,i=0,j=0;
	 p=&a[0];
	 q=&b[0];
	 v=(int *)malloc(sizeof(int)*10);
	 r=(char *)malloc(sizeof(int)*k);
	 while(i<10)
	 {
		 v[i]=10;
		 i++;
	 }
	 i=0;
	 while(*p!='\0')
	 {
		 if(*q=='\0')
		 {
			 p++;
			 i=0;
			 q=&b[0];
		 }
		 if(*p==*q&&v[i]!=1||*p==(int)*q-32||*p==(int)*q+32)
		 {
			 r[j]=*p;
			 v[i]=1;
			 p++;
			 q=&b[0];
			 i=0;
			 j++;
		 }
		 else
		 {
			 q++;
			i++;
		 }
	 }
	 r[j]='\0';
	 if(j==0)
		 return "";
	 else
	 return r;
}