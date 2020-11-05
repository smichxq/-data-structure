#include<stdio.h>
#include<stdlib.h>
typedef struct StackNode{
    int Data;
    struct StackNode *next;
}Stack;

Stack *top = NULL;
//初始化创建头节点
int Init(){
    top = (Stack*)malloc(sizeof(top));
    top->next = NULL;
    if (top==NULL)
    {
        return -1;
    }
    
    return 1;  
}
//判断栈空
int IsEmpty(Stack *tp){
    if (tp->next==NULL)
    {
        return 1;
    }
    return 0;
}
//压栈
int Push(Stack *tp,int Data){
    Stack *p;
    p = (Stack*)malloc(sizeof(p));
    p->Data = Data;
    p->next = tp->next;        //如果没有节点，top->next==NULL 如果有节点 top->next==第一个节点 新节点
    if (!p)
    {
        printf("分配空间失败\n");
        return 0;
    }
    
    top->next = p;
    return 1;
}
//出栈
int Pop(Stack *tp,int *Data){
    //因为传进来的是char类型的变量地址&变量
    //就相当于 形参char *Data = &变量
    //那么*Data就是主函数的变量
    Stack *Dp;

    *Data = tp->next->Data;      //结构体的Data为字符串

    Dp = tp->next;
    tp->next = tp->next->next;
    free(Dp);
    /*if (!Data)      //如果Data没有指向栈顶元素 为NULL NULL取反为真值 如果Data指向了元素，NULL取反为假
    {
        printf("未能弹出");
        return 0;
    }*/
    return 1;
}
//取栈顶元素
int GetTop(Stack *tp,int *Data){
    Stack *Dp;
    *Data = tp->next->Data;
    Dp = tp->next;
    tp->next = tp->next->next;
    free(Dp);
    return 1;
}
void Print(Stack *tp){
    while (tp->next!=NULL)
    {
        tp = tp->next;
        printf("%c",tp->Data);
    }
}

int main(){
    int Data;
    Init();
    printf("Stack is empty? ");
    printf("%d\n",IsEmpty(top));
    Push(top,1);
    Push(top,2);
    Push(top,3);
    printf("Stack is empty? ");
    printf("%d \n",IsEmpty(top));
    Print(top);
    Pop(top,&Data);
    printf("\n");
    printf("Pop element:%c\n",Data);
    printf("\n");
    Print(top);
    printf("\n");
    GetTop(top,&Data);
    printf("%c\n",Data);
    Print(top);
}

/*int main(){
    Init();
    

}*/

