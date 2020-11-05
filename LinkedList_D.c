#include<stdlib.h>
#include<stdio.h>

typedef struct LinkNodeD{
    char Data;
    struct LinkNodeD *p,*n;
}LinkNodeD,*PLinkNodeD;


//创建
PLinkNodeD Create(){
    PLinkNodeD Head,p,np;
    char ch;
    Head = (PLinkNodeD)malloc(sizeof(p));
    Head->p = Head;
    Head->n = NULL;
    np = Head;
    ch = getchar();
    while (ch!='\n')
    {
        p = (PLinkNodeD)malloc(sizeof(p));
        p->p = np;
        np->n = p;
        p->n = NULL;
        p->Data = ch;
        np = p;
        ch = getchar();

    }

    return Head;
    

}
//输出
void Print(PLinkNodeD Head){
   
    while (Head->n!=NULL)
    {
        printf("%c  ",Head->n->Data);
        Head = Head->n;   
    }
    printf("\n");
    
}
//按位置插入
void Ins(PLinkNodeD Head,int i,char ch){
    int j = 0;
    PLinkNodeD L;
    L = (PLinkNodeD)malloc(sizeof(L));
    
    while (Head->n!=NULL)
    {
        ++j;
        if (j==i)
        {
            L->n = Head->n;
            L->p = Head;
            Head->n->p = L;
            Head->n = L;
            L->Data = ch;
            break;
        
        }
        Head = Head->n;
        
    }
    
}
//删除
void Del(PLinkNodeD Head,int j){
    int i = 0;
    PLinkNodeD D;
    while (Head->n!=NULL)
    {
        ++i;
        if (i==j)
        {
            D = Head->n;        //要删除的节点
            Head->n = Head->n->n;
            if (Head->n == NULL)
            {
                free(D);
                break;
            }
            
            Head->n->p = Head;
            free(D);
            break;
        }
        
        Head = Head->n;
    }
    
}
int main(){
    PLinkNodeD head;
    head = Create();
    printf("Source: ");
    Print(head);
    Ins(head,1,'X');
    printf("Insert X in 1: ");
    Print(head);
    Ins(head,3,'C');
    printf("Insert C in 3: ");
    Print(head);
    Del(head,1);
    printf("Delete 1: ");
    Print(head);
    Del(head,3);
    printf("Delete 3: ");
    Print(head);
    Del(head,2);
    printf("Delete 2: ");
    Print(head);
    Ins(head,1,'B');
    printf("Insert B in 1");
    Print(head);
    Del(head,1);
    printf("Delete 1: ");
    Print(head);
    return 0;

}

