#include<stdio.h>
#include<stdlib.h>

typedef struct Std
{
    char* name;
    long id;
    char* class;
    char* sex;
    int A;
    int B;
    struct Std* next;
}Std;

typedef struct Head{
    Std* f;
    Std* r;
    char* stdNum;
}Head;

Head* init(){
    Head* head = NULL;

    head = (Head*)malloc(sizeof(head));

    head->stdNum = 0;
    head->f = NULL;
    head->f = NULL;
    return head;
    
    //head->next = (Std*)malloc(sizeof(Std));

}
/*
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
*/
//增
int add(Head* head,char* name,long id,char* class,char* sex,int A,int B){
    Std s;
    Std* p = NULL;
    if (!head->stdNum)
    {
        head->stdNum++;
        head->r = head->f = (Std*)malloc(sizeof(s));
        head->f->name = name;
        head->f->id = id;
        head->f->class = class;
        head->f->sex = sex;
        head->f->A = A;
        head->f->B = B;
        head->f->next = NULL;
        if (!head->f)
        {
            return 0;
        }
        return 1;
        
        
    }
    p = head->f;
    while (p)
    {
        if (p->id == id)
        {
            printf("id readd! \n");
            return 0;
        }
        p = p->next;
    }
    
    
    head->stdNum++;
    head->r->next = (Std*)malloc(sizeof(s));
    head->r = head->r->next;
    head->r->name = name;
    head->r->id = id;
    head->r->class = class;
    head->r->sex = sex;
    head->r->A = A;
    head->r->B = B;
    head->r->next= NULL;
    if (!head->r)
    {
        return 0;
    }
    return 1;
}
//删
int del(Head* head,long id){
    Std* p = head->f;
    Std* tempP = NULL;
    while (p)
    {
        if(p->id == id){
            tempP->next = p->next;
            free(p);
            return 1;
        }
        tempP = p;
        p = p->next;
    }
    return 0;
    
}
void print(Head* head){
    Std* p = NULL;
    p = head->f;
    printf("id       name       sex       class       A      B\n");
    while (p)                  //p为空，！p为真 p不为空，！p为假
    {
        printf("%d        ",p->id);
        printf("%s      ",p->name);
        printf("%s      ",p->sex);
        printf("%s       ",p->class);
        printf("%d    ",p->A);
        printf("%d\n",p->B);
        p = p->next;
        
    }
    
}
int main(){
    Head* head = NULL;
    head = init();
    add(head,"smith",1,"1222","male",100,100);
    add(head,"smith",2,"1222","male",100,100);
    del(head,2);
    //add(head,"smith",1,"1222","male",100,100);
    print(head);

    return 0;
}