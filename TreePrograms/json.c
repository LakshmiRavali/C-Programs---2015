//Convert the given JSON file to nrmal file with proper indendation.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


void validation(FILE *fp_input, FILE *fp_output)
{
	int i = 0,flag=1,j=0;
	char c;
	while (!feof(fp_input))
	{
		j = 0;
		c = fgetc(fp_input);
		if (c == ':')
		{
			fputc(c, fp_output);
			while ((c = fgetc(fp_input)) != ' '&& c!='}' && c!=']'&& c!='{' &&c!='[')
			{
				fputc(c, fp_output);
				c = fgetc(fp_input);
				if (c == ','&& c != '}' && c != ']'&& c != '{')
				{
					fputc(c, fp_output);
					fprintf(fp_output, "\n");
					fseek(fp_output, i, SEEK_CUR);
				}
				else
					fseek(fp_input, -1, SEEK_CUR);
				//i++;
				j++;
			}
			if (c==' '||j!=0)
				c = fgetc(fp_input);
			if (c == '[' && j==0)
			{
				fputc(c, fp_output);
				fprintf(fp_output, "\n");
				i = i + 10;
				fseek(fp_output, j, SEEK_CUR);
				//c = fgetc(fp_input);
				//flag = 1;
			}
			else
			{
				fseek(fp_input, -2, SEEK_CUR);
				//c = fgetc(fp_input);
			}
		}
		else if (c != '['&&c != '{')
		{
			if (c != ']'&&c != '}')
			{
				fputc(c, fp_output);
				c = fgetc(fp_input);
				if (c == ',')
				{
					fputc(c, fp_output);
					fprintf(fp_output, "\n");
					fseek(fp_output, i, SEEK_CUR);
				}
				else
					fseek(fp_input, -1, SEEK_CUR);
			}
			else
			{
				i = i - 10;
				fprintf(fp_output, "\n");
				fseek(fp_output, i, SEEK_CUR);
				fputc(c, fp_output);
				c = fgetc(fp_input);
				if (c == ',')
					fputc(c, fp_output);
				else if (c == -1)
					break;
				else
					fseek(fp_input, -1, SEEK_CUR);
			}
			flag = 0;
		}
		else
		{
			if (flag == 0)
			{
				fprintf(fp_output, "\n");
				fseek(fp_output, i, SEEK_CUR);
			}
			fputc(c, fp_output);
			fprintf(fp_output, "\n");
			i = i + 10;
			fseek(fp_output, i, SEEK_CUR);
			flag = 1;
		}
	}
	if (i != 0)
	{
		printf("Entered data is not valid");
	}
}

void main()
{
	FILE *fp_input = fopen("input1.json", "r+");
	FILE *fp_output = fopen("output.txt", "w");
	validation(fp_input, fp_output);
	fclose(fp_input);
	fclose(fp_output);
	_getch();
}