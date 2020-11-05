#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    1.注意,如果DataType位char类型,结构体内部必须定义为char* Data
    
    同时,GetHead方法不能用常规传指针方法来获取字符串,因为char* Data
    
    的值是字符串常量区的地址,通过在主函数定义一个char* ch类型并将其传给
    
    函数的方法是行不通的,因为实参传给形参的是值,也就是char* ch指向的地址,
    
    调用函数后,形参与实参指向相同地址,但是!!!!,形参只能访问其指向的地址,

    并不能将值改变，因为指向的地址时字符串常量区

    */


typedef char DataType;
//定义节点
typedef struct Node{
    DataType* Data;
    struct Node* Next;
}LinkedNode;
//定义两指针
typedef struct Point{
    LinkedNode* front;
    LinkedNode* rear;
}Point;

//初始化
LinkedNode* Init(Point* Pp){
    /*

    为什么传进来的结构体指针在函数调用完后无法访问结构体?

    当传进来指针时,本质上是传实参的值,也就是实参指向的地
    
    址,函数的形参也指向实参指向的内存区域,在本例中,主函

    数声明了一个指针,并未指向,但是系统默认会分配一个值
    
    给实参,当实参传给形参时,实际上传给了形参地址,在被

    调函数中,形参虽然与实参指向同一个地址,但是malloc

    函数返回了一个地址给形参,形参便与实参断开连接,没

    有任何联系,在被调函数调用调用完毕,与之有关的变量

    全部释放(malloc除外)

    */

    LinkedNode* LNp = NULL;

    LNp = (LinkedNode*) malloc(sizeof(LNp));

    Pp->front = Pp->rear = LNp;

    LNp->Next = NULL;

    if (!LNp)
    {
        printf("Init error!\n");
        return NULL;
    }
    printf("Init done!\n");
    return LNp;
    
    
}


/* 

'a'与"a"?

前者表示的是一个ASCII值,后者表示的是字符串

*/
//入队 字符串始终在常量区，结构体的Data指向的是常量区字符串首地址，所以传首地址
void InQueue(Point* Pp,DataType* ch){

    LinkedNode* p = NULL;

    //申请新节点
    p = (LinkedNode*)malloc(sizeof(p));
    
    //新节点next指向NULL
    p->Next = Pp->rear->Next;

    //上一个节点的（相对于新节点）rear操作节点next指向新节点
    Pp->rear->Next = p;

    //新节点赋值
    p->Data = ch;

    //移动rear到新节点
    Pp->rear = p;
     
    if (!p)
    {
        printf("InQueue error \nMalloc failed \n");
        return;
        
    }
    printf("InQueue done!\n");
}
//出队  传进去变量地址 形参就可以操作传进去的变量 除了char类型

//如果为char类型，可以：
                    //①：传进去字符数组利用字符数组的特性
                    //②：利用malloc来接收字符串
void OutQueue(Point* Pp,char* ch){

    char* d;

    LinkedNode* p = NULL;

    if (!Pp->front->Next)       //null即为假
    {
        printf("OutQueue error:Empty Queue\n");

        return;
    }

    p = Pp->front->Next;

    Pp->front->Next = p->Next;

    ch[0] = *p->Data;

    

    free(p);



    printf("OutQueue done! \n");

}
//判空
int IsEmpty(Point* p){
    if (!p->front->Next)
    {
        return 1;
    }

    return 0;
    
}
//拿头
void GetHead(Point* p,char* ch){
    if (IsEmpty(p))
    {
        printf("Is Empty!\n");
        return;
    }
    ch[0] = *p->front->Next->Data;
    printf("GetHead done!\n");

}

//输出
void print(Point *p){

    //申请局部变量为了避免移动指针改变rear和front节点
    LinkedNode *pp = p->front;

    //当节点的next为NULL（NULL就是0）跳出循环
    while (pp->Next)
    {   
        pp = pp->Next;
        printf("%c\n",*pp->Data);
        
    }
    
}

int main(){
    LinkedNode *l = NULL;
    Point P,*p = NULL;
    p = &P;
    l = Init(p);
    char a[1];
    InQueue(p,"A");
    printf("%d\n",IsEmpty(p));
    GetHead(p,a);
    printf("%c\n",a[0]);
    OutQueue(p,a);
    printf("%c\n",a[0]);
    printf("%d",IsEmpty(p));



    
}