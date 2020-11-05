#include<stdio.h>
#include<stdlib.h>



typedef struct LinkNode{
    char Data;       
    struct LinkNode *p;
}LN,*LNP;

LNP Head;

//头插法
void CreateLinkList_Head(){
    char ch;
    LN *p;      //结构体指针
    p = (LN*)malloc(sizeof(p));     //建立头节点 
    Head = p;       //头指针指向头节点
    Head->p = NULL;     //头节点指向NULL
    //ch = getchar();
    while(ch!='\n'){
        p = (LN*)malloc(sizeof(p));     //建立节点
        p->p = Head->p;     //将头节点 指针域 赋给 当前节点 指针域 就是将当前节点指针域NULL
        p->Data = ch;       //数据域赋值
        Head->p = p;        //头节点指针域 指向 新节点
        ch = getchar();
    }

}
//尾插法
void CreateLinkList_Button(){
    char ch;
    LNP p,ps;        //p start 
    p = (LNP)malloc(sizeof(p));
    Head = p;
    Head->p = NULL;
    ps = p;
    ch = getchar();
    while (ch!='\n'){        
        //ch = getchar() 先读取会导致读取 \n 然后存入链表
        p = (LNP)malloc(sizeof(p));
        p->Data = ch;
        ps->p = p;
        ps = p;
        ps->p = NULL;
        ch = getchar();
    }
    

}
//H为头插法 B为尾插法
void Init(char Option){
    if (Option=='H'){
        CreateLinkList_Head();
    }
    else if(Option=='B'){
        CreateLinkList_Button();
    }
    else
    {
        printf("请输入'H'(头插法),'B'(尾插法)");
    }
}

void Print(){
    LNP p1 = Head;     //头指针给p1
    while (p1!=NULL)
    {
        p1 = p1->p;
        //printf("%c",p1->Data);      //%c输出单个字符
    }
    

}
//位置查找
LNP PSearch(int Position){
    if (Position<1)
    {  
        printf("Out of index! \n");
        return Head;
    }
    
    int i = 0;
    LNP p;
    p = Head;
    while (p!=NULL)
    {
        ++i;
        p = p->p;
        if(Position == i){
            return p;
        }

    }
    printf("NOt found! \n");
    return Head;
    
}
//值查找
int VSearch(char Value){
    LNP p = Head;
    int i = 0;
    char ch;
    while (p->p!=NULL)
    {
        ++i;
        p = p->p;
        ch = p->Data;
        if (ch == Value)
        {

            return i;
            
        }
        
    }
    return 0;
    
}

int main(){
    LNP p;
    int Positopn;
    Init('B');
    Print(Head);
    //p = PSearch(5);
    //printf("%c",p->Data);
    Positopn = VSearch('G');
    printf("%d \n",Positopn);
      
    return 0;
}

