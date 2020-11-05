#include <stdio.h>
#define Max 5
typedef struct Queue* P;

typedef struct Queue{
    int Data[5];
    int front,rear;
}queue;

queue q;


//初始化
P Init(){
    //queue q;
    P p;
    p = &q;
    p->front = p->rear = 0;         //初始化均为0
    return p;
}
//队满
int IsFull(P p){
    int i;
    i = p->rear;
    if((++i%Max)!=(p->front)){
        return 0;
    }
    return 1;
}
//入队
void EnQueue(P p,int Data){
    /*
    if (IsFull(p))
    {                               //为什么会造成指针错误
        printf("full\n");
        return;
    }
    */
   int i;
   i = p->rear;
   if (++i%Max==p->front)
   {
       return;
   }
   

    p->Data[(++p->rear)%Max] = Data;
    
}
//出队
void OutQueue(P p,int *Data){
    if(p->front!=p->rear){
        *Data = p->Data[++p->front%Max];
        return;
    }
    printf("Empty\n");
    return;
}
//得到队头
int GetFront(P p){
    int front = p->front;
    return p->Data[++front%Max];
}




int main(){
    //ueue *p;
    int Data;
    P p;
    p = Init();
    Init();
    EnQueue(p,1);
    EnQueue(p,2);
    EnQueue(p,3);
    EnQueue(p,4);
    //EnQueue(p,1);         //队满测试
    //printf("%d",p->Data[p->rear]);    //入队正确性测试
    //IsFull(p);
    if(IsFull(p)){
        printf("full");           //为什么会造成数组值混乱?     注意作用域 在Init函数内部申请的结构体会在运行完后(某一时刻)回收 而printf函数促使了这个回收 

    }
    else{
        EnQueue(p,4);
    }
    OutQueue(p,&Data);
    //printf("%d",Data);
    Data = GetFront(p);
    printf("%d",Data);
    return 0;

}