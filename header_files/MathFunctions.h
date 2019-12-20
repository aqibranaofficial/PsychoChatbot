#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isMath(const char [256]);
void applyMath(int, int, int);
void giveNumbers(const char [256], int*, int*);
int isMath(const char str[256])
{
    int i, j=0;
	char str2[256]={};
    char *add[5]={"addition","add","sum","plus", "+"};
    char *product[5] = {"multiplication","multiply","product","times", "*"};
    char *subtract[5] = {"subtraction","subtract","minus","deduct", "-"};
    char *divide[3] = {"division","divide", "/"};
    strcpy(str2, str);
    char *token = strtok(str2, " ");
    while(token!=NULL)
    {
    	for(i=0;i<5;i++)
    	{
    		if(strcmp(token, add[i])==0)
    			{
    				j=1;
    				break;
				}
		}
		if(j==1)
		return j;
		for(i=0;i<5;i++)
    	{
    		if(strcmp(token, product[i])==0)
    			{
    				j=2;
    				break;
				}
		}

		if(j==2)
		return j;
		for(i=0;i<5;i++)
    	{
    		if(strcmp(token, subtract[i])==0)
    			{
    				j=3;
    				break;
				}
		}
		if(j==3)
		return j;
		for(i=0;i<3;i++)
    	{
    		if(strcmp(token, divide[i])==0)
    			{
    				j=4;
    				break;
				}
		}
		if(j==4)
		return j;

        token = strtok(NULL, " ");
    }
    return j;
}
void applyMath(int i, int a, int b)
{
    int j;
    char str[50] = {};
    char num[10]= {};
    switch(i)
    {
        case 1: j = a + b; break;
        case 2: j = a * b; break;
        case 3: j = a - b; break;
        case 4: j = a / b; break;
    }
    printf("It would be, %d\n\n", j);
    itoa(j, num, 10);
    strcpy(str, "say.vbs \"It would be, ");
    strcat(str, num);
    strcat(str, "\"");
    system(str);
}
void giveNumbers(const char str[], int* a, int* b)
{
    char s[50] = {};
    strcpy(s, str);
	char s1[10] = {};
	char s2[2][10] = {};
	char c;
	int i,digit, j=0;
	char *token = strtok(s, " ");
	while(token!=NULL)
    {
        strcpy(s1, token);
        if(s1[0]>='0' && s1[0]<='9')
            {
                strcpy(s2[j], s1);
                j++;
            }
        token = strtok(NULL, " ");
    }
	for(i=0;i<strlen(s2[0]);i++)
	{
		c = s2[0][i];
		if(c>='0' && c<='9') //to confirm it's a digit
		{
			digit = c - '0';
			*a = *a*10 + digit;
		}
	}
	for(i=0;i<strlen(s2[1]);i++)
	{
		c = s2[1][i];
		if(c>='0' && c<='9') //to confirm it's a digit
		{
			digit = c - '0';
			*b = *b*10 + digit;
		}
	}
}
