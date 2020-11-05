#include<stdio.h>
#include<stdlib.h>

typedef struct Std
{
    char* name;
    char* id;
    char* class;
    char* sex;
    char* A;
    char* B;
    struct Std* next;
}Std;

typedef struct Head{
    Std* next;
    char* stdNum;
}Head;

Head* init(){
    Head* head = NULL;

    head = (Head*)malloc(sizeof(Std));

    head->stdNum = 0;
    head->next = NULL;

    return head;
    
    //head->next = (Std*)malloc(sizeof(Std));

}

int fr(Head* head){
    FILE* fr = fopen("Std.txt","r");
    char ch;        //并不是字符串
    int flag = 0;
    int count = 0;
    while ((ch=getch(fr))!=EOF)
    {
        if(ch==' ')
        {
            flag++;
        }
        if (flag%5 == 0)
        {
            
        }
        
        
        
    }
    
}

int add(Head* head){
    
    if (head == NULL)
    {
        return 0;
    }

    




    

    

}