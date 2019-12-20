#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int isMusic(const char [256]);
int playMusic();
int isMusic(const char str[256])
{
    char str2[256]={};
    strcpy(str2, str);
    char *token = strtok(str2, " ");
    while(token!=NULL)
    {
        if(strcmp(token, "play")==0 || strcmp(token, "song")==0)
            return 1;
        token = strtok(NULL, " ");
    }
    return 0;
}
int playMusic()
{
    int i;
	char music_name[50], str[100]={}, music_str[100]={}, action[10], ch;
    printf("Psycho: Which song do you want to listen?\n\n");
    system("say.vbs \"Which song do you want to listen?\"");
    printf("You: ");
    scanf("%s", music_name);
    printf("Psycho: Playing %s", music_name);
    strcpy(music_str, "say.vbs \"Playing ");
    strcat(music_str, music_name);
    strcat(music_str, "\"");
    system(music_str);
    s_tolower(music_name, music_name);
    strcpy(str, music_name);
    strcat(str, ".mp3");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".\n\n");
    system(str);
    printf("You: ");
    scanf("%s", action);
    s_tolower(action, action);
    if(strcmp(action, "stop")==0)
    {
        system("taskkill /im vlc.exe");
        printf("Psycho: Stopped.\n\n");
        system("say.vbs \"Stopped\"");
        return 0;
    }
}
