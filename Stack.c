#include<stdio.h>
#define MAX 5
typedef struct Node{
    int Data[MAX];
    int top;
}Stack;

void Init(Stack *p){
    p->top = -1;
}
int Push(Stack *p, int Data){
    if(p->top==MAX-1){
        printf("full!\n");
        return -1;

    }
    else{
        ++p->top;
        p->Data[p->top] = Data;
        return 1;

    }
}
int isEmpty(Stack *p){
    if(p->top==-1){
        return 1;
    }
    return 0;
}
int pop(Stack *p, int *Data){
    if(isEmpty(p)){
        printf("Empty!\n");
        return 0;
    }

    else{
        *Data = p->Data[p->top];
        --p->top;
        return 1;
    }

}
int getTopStack(Stack *p){
    if(isEmpty(p)){
        printf("isEmpty!\n");
        return;
    }
    else{
        return p->Data[p->top];
    }
}


int main(){
    Stack *p,s;         //*p *是运算符 表示取值 p是值,存放地址
    int *Data;
    p = &s;             //指针存放s地址
    Init(p);
    printf("Init...................done!\n");
    printf("isEmpty? %d \n",isEmpty(p));
    printf("pushing............done!\n");
    Push(p,1);
    Push(p,2);
    Push(p,3);
    Push(p,4);
    Push(p,5);
    printf("The top element is:%d\n",getTopStack(p));
    printf("pushig more........\n");
    Push(p,6);
    pop(p,Data);
    printf("poping..............done!\n");
    printf("The top element is:%d\n",getTopStack(p));
    printf("poping more.........\n");
    pop(p,Data);
    printf("The top element is:%d\n",getTopStack(p));
    pop(p,Data);
    printf("The top element is:%d\n",getTopStack(p));
    pop(p,Data);
    printf("The top element is:%d\n",getTopStack(p));
    pop(p,Data);
    printf("The top element is:%d\n",getTopStack(p));
    pop(p,Data);


}