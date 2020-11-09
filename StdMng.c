#include<stdio.h>
#include<stdlib.h>

typedef struct Std
{
    char* name;
    char* class;
    char* sex;
    int grade;
    int A;
    int B;
    long id;
    struct Std* next;
    struct Std* front;
}Std;

typedef struct Head{


    int stdNum;
    Std* f;
    Std* r;
    Std* next;           
    
    
}Head;
//增加头节点
Head* init(){
    Head* head = NULL;
    Head head1;
    //head = (Head*)malloc(sizeof(head));  //参数为Head指针为什么会出错？

    head = (Head*)malloc(sizeof(head1));        

    head->stdNum = 0;
    head->f = NULL;
    head->r = NULL;
    head->next = NULL;
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
int add(Head* head,char* name,long id,char* class,int grade,char* sex,int A,int B){
    Std s;
    Std* p = NULL;
    if (!head->stdNum)
    {
        head->stdNum++;
        head->next = head->r = head->f = (Std*)malloc(sizeof(s));
        head->f->name = name;
        head->f->id = id;
        head->f->class = class;
        head->f->grade = grade;
        head->f->sex = sex;
        head->f->A = A;
        head->f->B = B;
        head->f->front = (Std*)head;
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
    head->r->next = (Std*)malloc(sizeof(s));        //上个结点的后驱连接新结点

    head->r->next->front = head->r;                 //新结点前驱指向上个结点 不能在尾指针移动到新结点后再指向前一个结点，因为在尾指针指向新结点后与前一个结点无联系
    head->r->next->next = NULL;                     //新结点后继为NULL
    
    head->r = head->r->next;                        //尾指针指向新结点

    head->r->name = name;
    head->r->id = id;
    head->r->class = class;
    head->r->grade = grade;
    head->r->sex = sex;
    head->r->A = A;
    head->r->B = B;

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
//改
int mdfy(Head* head,char* name,long id,char* class,int grade,char* sex,int A,int B){

    
    Std* p = head->f;
    while (p)
    {
        if(p->id == id)
        {
            p->name = name;
            p->id = id;
            p->class = class;
            p->grade = grade;
            p->sex = sex;
            p->A = A;
            p->B = B;
            return 1;
        }
        p = p->next;
    }
    return 0;
    
}
//查
int sch(Head* head,long id){
    Std* p = head->f;

    while (p)
    {
        if(p->id == id)
        {
            p->id = id;
            printf("found id: %d name: %s sex: %s class: %s grade: %d A: %d B: %d",p->id,p->name,p->sex,p->class,p->grade,p->A,p->B);
            return 1;
        }
        p = p->next;
    }
    printf("not found!");
    return 0;

}
//排
/*
void sort(Head* head){
    Std* min = NULL;
    
    while (head->f)
    {
        min = head->f;
        head->r = head->f;

        while (head->r)
        {
            if(head->r->id < min->id)
            {
                min = (head->r);

            }
            head->r = head->r->next;
        }

        if (min == head->f)
        {
            if (head->f->next == NULL)
            {
                head->f = head->f->next;
                continue;
            }
            
            head->f = head->f->next;
            continue;
        }
        
        if (head->f->next == NULL)
        {
            head->f = head->f->next;
            continue;
        }
        if (head->f->next == min)
        {
            if (min->next == NULL)
            {
                head->f->front->next = min;
                head->f->next = min->next;
                min->front = head->f->front;
                min->next = head->f;
                head->f->front = min;
                head->f = head->f->next;
                continue;
            }

            if (min->next != NULL)
            {
                head->f->front->next = min;//没有将min成功赋值
                head->f->next = min->next;
                min->next->front = head->f;
                min->front = head->f->front;
                min->next = head->f;
                head->f->front = min;

                head->f = head->f->next;
                continue;
            }

            
            
        }
        if (min->next == NULL)
        {
            head->f->front->next = min;
            head->f->next = min->front;
            min->front = head->f->front;
            head->f->front = head->f->next;
            head->f->next = NULL;
            head->f->front->front = min;
            head->f->front->next = head->f;
            head->f = min;
            head->f = head->f->next;
            continue;

        }

        if (min->next != NULL)
        {
            head->f->front->next = min;
            min->next->front = head->f;
            min->front = head->f->front;
            head->f->front = min->next;
            
            head->f->front = head->f->next;
            head->f->next = min->next;
            min->next = head->f->front;
            min->next->front = min;
            min->next->next = head->f;

            head->f = head->f->next;
            continue;
        }
        
        
        
        
        
    }
    
  


}
*/

void sort(Head* head){
    Std* MAX = NULL;
    //Std* MAXf = NULL;//用双链表表示

    int flag = 1;

    
    Std* p = head->f;
    Std* pp = p;
    //只有一个直接退出
    if (head->stdNum == 1) 
    {
        printf("Just one!");
        return;
    }

    while (p)
    {
        pp = p;
        MAX = p;

        while(pp)
        {   
            if (pp->id > MAX->id)
            {
                MAX = pp;
                
            }

            pp = pp->next; 

        }

        if (MAX == head->f)
        {
            p = p->next;
            flag = 0;
            head->f = head->next;
            continue;
        }
        


        //MAX前一个next指向后一个
        MAX->front->next = MAX->next;
        //MAX不为最后一个
        if (MAX->next)
        {
            //MAX后一个front指向前一个
            MAX->next->front = MAX->front;
        }
        

        MAX->next = head->next;

        head->next = MAX;

        MAX->next->front = MAX;



        


        //p！=MAX
        if (p != MAX)
        {
            MAX->front = (Std*)head;
            //p = p->next;
            head->f = head->next;
            continue;
        }


        p = MAX->front->next;
        MAX->front = (Std*)head;
        head->f = head->next;
        
    
    
    
    }
}


//输出
void print(Head* head){
    Std* p = NULL;
    p = head->next;
    printf("id       name       sex       class     grade       A      B\n");
    while (p)                  //p为空，！p为真 p不为空，！p为假
    {
        printf("%d        ",p->id);
        printf("%s      ",p->name);
        printf("%s      ",p->sex);
        printf("%s       ",p->class);
        printf("%d       ",p->grade);
        printf("%d    ",p->A);
        printf("%d\n",p->B);
        p = p->next;
        
    }
    
}
int main(){
    
    Head* head = NULL;

    head = init();
    //fflush(stdout);
    //printf("11");

    add(head,"smith",5,"计1804",1,"male",100,100);
    add(head,"smith",1,"1222",1,"male",100,100);
    add(head,"smith",4,"1222",1,"male",100,100);
    add(head,"smith",6,"1222",1,"male",100,100);
    add(head,"smith",3,"1222",1,"male",100,100);
    add(head,"smith",2,"1222",1,"male",100,100);
   

    printf("before sort: \n");
    print(head);
    sort(head);
    printf("sorted: \n");
    print(head);





}