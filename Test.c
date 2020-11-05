#include <stdio.h>
#include <stdlib.h>

int fr(){
    FILE* fr = fopen("Std.txt","r");
    char ch;        //并不是字符串
    char* chh = NULL;
    int flag = 0;
    int count = 0;
    while ((ch=getch(fr))!=EOF)
    {

            
        
    }
    
}

int main(){
    FILE* fr = NULL;
    FILE* fw = NULL;

    char ch;
    if ((fr=fopen("Std.txt","r"))==NULL)
    {
        printf("NULL");
        exit(0);
    }
    if ((fw=fopen("w.txt","w"))==NULL)
    {
        printf("NULL");
        exit(0);
    }
    int i = 0;
    while ((ch=fgetc(fr))!=EOF)
    {
        //putchar(ch);
        if (ch=='\n')
        {
            i++;
        }
        
        putc(ch,fw);
    }
    fclose(fr);
    fclose(fw);
    printf("%d",i);
    return 0;

    
}

