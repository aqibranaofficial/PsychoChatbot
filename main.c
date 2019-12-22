#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header_files/DateAndTimeFunctions.h"
#include "header_files/GeneralFunctions.h"
#include "header_files/MusicFunctions.h"
#include "header_files/MathFunctions.h"

int main()
{
    int j, k;
	char input[256], output[256];
    printf("Hello, How can Psycho help you?\n\n");
    system("say.vbs \"Hello, How can Psycho help you?\"");
    do
    {
        printf("You: ");
        gets(input);
        s_tolower(input, output);
        if(isMusic(output))
        {
            playMusic();
            fflush(stdin);
            continue;
		}
		if(isMath(output))
		{
			int a=0, b=0;
			j= isMath(output);
			giveNumbers(output, &a, &b);
			applyMath(j, a, b);
			continue;
		}
		if(isJoke(output))
        {
            jokes();
            continue;
        }
        if(isTime(output))
        {
            dateAndTime(output);
            continue;
        }
        if(isApp(output))
        {
            k = isApp(output);
            startApp(k);
            continue;
        }
        if(strcmp(output, "bye")==0 || strcmp(output, "exit")==0 || strcmp(output, "good bye")==0)
        {
            printf("Psycho: See you later!\n");
            system("say.vbs \"See you later.\"");
            exit(0);
        }
        getInput(output);
    }
    while(1);
}


