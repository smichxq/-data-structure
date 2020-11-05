#include <stdio.h>
#include <stdlib.h>

typedef struct L *Prtl;
#define MaxN 20
struct L{
    int a[MaxN];
    int Last;
};


Prtl Create(){
    int i =0;
    Prtl Pc;
    Pc = (Prtl)malloc(sizeof(struct L));   
    Pc->Last=9;
    while(i<=9){
        Pc->a[i]=i;
        ++i;
    }
    Pc->a[0] = 5;
    Pc->a[5] = 12;

    return Pc;
}


int Insert(const Prtl pc,int p,int value){
    if(p>pc->Last || p<0){printf("Insert Wrong Position!");return -1;}

    for(int i = pc->Last;i>=p;i--){
        pc->a[i+1] = pc->a[i];
    }

    pc->a[p]=value;

    pc->Last++;

}

int Delete(const Prtl Pc,int p){
    if(p<0 || p>Pc->Last-1){printf("Delete Wrong Position!");return -1;}

    for(int i = p;i<=Pc->Last-1;i++){
        Pc->a[i] = Pc->a[i+1];
    }
    
    Pc->Last--;
}

int search(Prtl Pc,int Num){
    int i=0;
    while(Pc->a[i]!=Num){
        ++i;
        if(i==MaxN){
            printf("未找到");
            return 0;
        }

    }
    printf("找到：%d",i+1);
    return 1;
}

void part(Prtl Pc){
    //时间复杂度为2n^2
    int a;
    int j=0;
    a = Pc->a[0];
    for(int i = 1;i<Pc->Last;i++){
        if (a>Pc->a[i])
        {
          Insert(Pc,j,Pc->a[i]);
          Delete(Pc,i+1); 
          j++; 
        }
        
        
    }
    printf("done! \n");
}


void Print(Prtl Pc){
    //printf("%d",Pc->a[0]);
    int i=0;
    while(i<Pc->Last){
        printf("%d ",Pc->a[i]);
        ++i;
    }
    printf("Done! \n");
}

int main(){
    struct L *p;

    Prtl Pc = Create();
    printf("source!\n");
    Print(Pc);
    part(Pc);
    printf("parted! \n");
    Print(Pc);
    

    Insert(Pc,0,12);
    printf("Insert!\n");
    Print(Pc);
    printf("Delete!\n");
    Delete(Pc,0);
    Print(Pc);
    
}


