#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
void s_tolower(const char [256], char [256]);
void getInput(const char [256]);
int isJoke(const char [256]);
void jokes();
void s_tolower(const char user_inp[256], char user_out[256])
{
    int i, j=0;
    for(i=0;i<256;i++)
    {
        if(user_inp[i]!='?' && user_inp[i]!='!' && user_inp[i]!='/' && user_inp[i]!='.' && user_inp[i]!=',')
        {
            user_out[j] = tolower(user_inp[i]);
            j++;
        }
    }
}
void getInput(const char input[256])
{
    int i=0;
    char array1[256], str[256], choice;
    FILE *fp = fopen("commands.txt", "r");
    if(fp==NULL)
    {
        printf("File Opening Error!");
        exit(0);
    }
    while(!feof(fp))
    {
        fgets(array1, 256, fp);
        if(strncmp(array1,input,strlen(input))==0)
        {
            fgets(array1, 256, fp);
            printf("Psycho: %s\n", array1);
            strcpy(str, "say.vbs \"");
            strcat(str, array1);
            strcat(str, " .\"");
            system(str);
            i=1;
        }
    }
    if(i==0)
    {
        printf("Psycho: I don't understand what you say, I will learn these things soon.\n");
        system("say.vbs \"I don't understand what you say, I will learn these things soon.\"");
    }
}
int isJoke(const char str[256])
{
    char str2[256]={};
    strcpy(str2, str);
    char *token = strtok(str2, " ");
    while(token!=NULL)
    {
        if(strcmp(token, "joke")==0)
            return 1;
        token = strtok(NULL, " ");
    }
    return 0;
}
void jokes()
{
    srand(time(0));
	int i;
	char str[256];
	char jokestr[256];
    char *str1[13] = {
                    "Waiter: And how did you find your steak sir? Customer: I just flipped a chip over, and there it was!",
                    "A man's credit card was stolen but he decided not to report it because the thief was spending less than his wife did.",
                    "David Hasselhoff walks into a bar and says to the barman, I want you to call me David Hoff. The barman replies Sure thing Dave... no hassle",
                    "A fish staggers into a bar. What can I get you? asks the landlord. The fish croaks Water...",
                    "What's the best thing about Switzerland? I don't know, but the flag is a big plus.",
                    "I invented a new word! Plagiarism!",
                    "Hear about the new restaurant called Karma? There's no menu: You get what you deserve.",
                    "Did you hear about the claustrophobic astronaut? He just needs a little space.",
                    "Why don't scientists trust atoms? Because they make up everything.",
                    "Where are average things manufactured? The satisfactory.",
                    "A man tells his doctor, Doc, help me. I'm addicted to Twitter! The doctor replies, Sorry, I don't follow you …",
                    "Why don't Calculus majors throw house parties? Because you should never drink and derive.",
                    "What's the different between a cat and a comma? A cat has claws at the end of paws; A comma is a pause at the end of a clause."
                      };
    strcpy(jokestr, str1[rand()%13]);
    printf("Psycho: %s\n\n", jokestr);
    strcpy(str, "say.vbs \"");
    strcat(str, jokestr);
    strcat(str, " . Hahah\"");
    system(str);
}
