#include<stdio.h>
#include<stdlib.h>



typedef struct LinkNode{
    char Data;       
    struct LinkNode *p;
}LN,*LNP;

//链表头指针
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

/*链表的逆置
    p         c       n
上一个结点 当前结点 下一个结点

核心思想
1.当前节点指向上一个结点
2.p开始移动到当前节点c
3.当前结点c移动到下一个结点n
4.检查c移动后是否为NULL，如果是，则逆置完毕，反之继续逆置
5.下一个结点n移动到当前结点c的下一个(检查溢出)

注意事项:
1.指针c移动前，如果n指向了结尾NULL，当c移动到下一个后，步骤5会溢出！
2.2个以及以下数量的链表不适用以上操作
*/

void ReList(){
    //链表头指针
    LNP p = Head;

    //跳过头节点
    p = p->p;

    //初始化三个指针
    LNP l,c,n;

    //l,c,n分别指向第1，2，3个元素
    l = p;
    c = l->p;
    n = c->p;

    //循环逆置部分
    while (1){
        //当前结点指向前一个
        c->p = l;
        
        //前一个指针移动到当前结点
        l = c;

        //当前指针移动到后一个
        c = n;

        //判断当前指针移动后是否为结尾NULL
        if (!c){break;}//从L开始遍历，因为当前指针c为NULL，那么前一个指针l一定是最后一个结点
        
        //指针n移动到当前指针c后一个
        n = c->p;
    }

    //循坏输出
    while (1){

        printf("%c",l->Data);
        
        //先输出最后一个值，再退出
        if (l==p){break;}

        l = l->p;
    }
    


}

int main(){
    LNP p;
    int Positopn;
    Init('B');
    Print(Head);
    ReList();
    //p = PSearch(5);
    //printf("%c",p->Data);
    // Positopn = VSearch('G');
    // printf("%d \n",Positopn);

      
    return 0;
}

