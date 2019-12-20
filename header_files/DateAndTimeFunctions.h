#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int isTime(const char [256]);
int dateAndTime(const char [256]);
void getTime();
void getDate();
void getDay();
void getYear();
void getMonth();
int isTime(const char str[256])
{
    char str2[256]={};
    strcpy(str2, str);
    char *token = strtok(str2, " ");
    while(token!=NULL)
    {
        if(strcmp(token, "time")==0 || strcmp(token, "date")==0 || strcmp(token, "day")==0 || strcmp(token, "month")==0 || strcmp(token, "year")==0)
            return 1;
        token = strtok(NULL, " ");
    }
    return 0;
}
int dateAndTime(const char str[256])
{
    char str2[256]={};
    strcpy(str2, str);
    char *token = strtok(str2, " ");
    while(token!=NULL)
    {
        if(strcmp(token, "time")==0)
            {
                getTime();
                return 0;
            }
        else if(strcmp(token, "date")==0)
            {
                getDate();
                return 0;
            }
        else if(strcmp(token, "day")==0)
            {
                getDay();
                return 0;
            }
        else if(strcmp(token, "month")==0)
            {
                getMonth();
                return 0;
            }
        else if(strcmp(token, "year")==0)
            {
                getYear();
                return 0;
            }
        token = strtok(NULL, " ");
    }
    return 0;
}
void getTime()
{
    char buffer[32];
    char str[100];
    unsigned int last;
    time_t timestamp;
    time(&timestamp);
    struct tm *ts = localtime(&timestamp);
    last = strftime(buffer, 32, "%I:%M %p", ts);
    buffer[last] = '\0';

    printf("Psycho: %s\n\n", buffer);
    strcpy(str, "say.vbs \"");
    strcat(str, buffer);
    strcat(str, ".\"");
    system(str);
}
void getDate()
{
    char buffer[50];
    char str[100], s[10];
    unsigned int last;
    time_t timestamp;
    time(&timestamp);
    struct tm *ts = localtime(&timestamp);
    last = strftime(buffer, 50, "%d, %B ", ts);
    buffer[last] = '\0';

    printf("Psycho: %s %d\n\n", buffer, ts->tm_year+1900);
    itoa(ts->tm_year+1900, s, 10);
    strcpy(str, "say.vbs \"");
    strcat(str, buffer);
    strcat(str, s);
    strcat(str, ".\"");
    system(str);
}
void getMonth()
{
    char buffer[32];
    char str[100];
    unsigned int last;
    time_t timestamp;
    time(&timestamp);
    struct tm *ts = localtime(&timestamp);
    last = strftime(buffer, 32, "%B", ts);
    buffer[last] = '\0';

    printf("Psycho: %s\n\n", buffer);
    strcpy(str, "say.vbs \"");
    strcat(str, buffer);
    strcat(str, ".\"");
    system(str);
}
void getDay()
{
    char buffer[32];
    char str[100];
    unsigned int last;
    time_t timestamp;
    time(&timestamp);
    struct tm *ts = localtime(&timestamp);
    last = strftime(buffer, 32, "%A", ts);
    buffer[last] = '\0';

    printf("Psycho: %s\n\n", buffer);
    strcpy(str, "say.vbs \"");
    strcat(str, buffer);
    strcat(str, ".\"");
    system(str);
}
void getYear()
{
    char str[100], s[10];
    time_t timestamp;
    time(&timestamp);
    struct tm *ts = localtime(&timestamp);
    printf("Psycho: %d\n\n", ts->tm_year+1900);
    itoa(ts->tm_year+1900, s, 10);
    strcpy(str, "say.vbs \"");
    strcat(str, s);
    strcat(str, ".\"");
    system(str);
}
