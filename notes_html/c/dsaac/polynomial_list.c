#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node;
struct list;
typedef int T;
typedef struct node node;
typedef struct list list;

struct node{
    int mi;
    T xi;
    node *next;
};

struct list{//第一个元素不存值
    node *root;
    int len;
};

list *csh()
{
    list *l;
    l=(list *)malloc(sizeof(list));
    l->len=0;
    l->root=(node *)malloc(sizeof(node));
    l->root->next=NULL;
    return l;
}

void clear(list *lp)
{
    list l;
    l = *lp;
    node *tp=l.root;
    while(tp!=NULL)
    {
        node *tp1=tp;
        tp=tp->next;
        free(tp1);
    }
    l.len=0;
    l.root=(node *)malloc(sizeof(node));
    l.root->next=NULL;
}
void insert(list *lp,int mi,T xi)//查入时按mi从大到小排序
{
    list l;
    bool flag=true;
    l = *lp;
    node* tp=l.root;
    while(tp->next!=NULL)
    {
        if(tp->next->mi==mi)
        {
            tp->next->xi+=xi;
            flag=false;
            break;
        }
        else if(tp->next->mi<mi)
        {
            node *temp =(node *)malloc(sizeof(node));
            temp->mi=mi;
            temp->xi=xi;
            temp->next=tp->next;
            tp->next=temp;
            l.len++;
            flag=false;
            break;
        }
        tp=tp->next;
    }
    if(flag)
    {
        node *temp =(node *)malloc(sizeof(node));
        temp->mi=mi;
        temp->xi=xi;
        temp->next=tp->next;
        tp->next=temp;
        l.len++;
    }
}
void jia(list *onep,list *twop,list *resultp)
{
    list one,two,result;
    one = *onep;
    two = *twop;
    result= *resultp;
    node *tp1=one.root;
    node *tp2=two.root;
    tp1=tp1->next;
    tp2=tp2->next;
    while(tp1!=NULL)
    {
        insert(&result,tp1->mi,tp1->xi);
        tp1=tp1->next;
    }
    while(tp2!=NULL)
    {
        insert(&result,tp2->mi,tp2->xi);
        tp2=tp2->next;
    }
}
void jian(list *onep,list *twop,list *resultp)
{
    list one,two,result;
    one = *onep;
    two = *twop;
    result= *resultp;

    node *tp1=one.root;
    node *tp2=two.root;
    tp1=tp1->next;
    tp2=tp2->next;
    while(tp1!=NULL)
    {
        insert(&result,tp1->mi,tp1->xi);
        tp1=tp1->next;
    }
    while(tp2!=NULL)
    {
        insert(&result,tp2->mi,-(tp2->xi));
        tp2=tp2->next;
    }
}
void cheng(list *onep,list *twop,list *resultp)
{
    list one,two,result;
    one = *onep;
    two = *twop;
    result= *resultp;

    node *tp1=one.root;
    tp1=tp1->next;
    while(tp1!=NULL)
    {
        node*tp2=two.root;
        tp2=tp2->next;
        while(tp2!=NULL)
        {
            insert(&result,tp1->mi+tp2->mi,tp1->xi*tp2->xi);
            tp2=tp2->next;
        }
        tp1=tp1->next;
    }
}
void print_dxs(list *lp)
{
    list l;
    l = *lp;
    node*tp=l.root;
    tp=tp->next;
    if(tp==NULL)
        printf("结果为空！");
    bool first=true;
    while(tp!=NULL)
    {
        if(tp->xi!=0)
        {
            if(tp->xi==1||tp->xi==-1)
            {
                if(first)
                {
                    if(tp->xi<0)
                        printf("-");
                    first=false;
                }
                else if(tp->xi>0)
                    printf("+");
                else
                    printf("-");
            }
            else
            {
                if(first)
                {
                    printf("%d",tp->xi);
                    first=false;
                }
                else
                    printf("%+d",tp->xi);
            }
            if(tp->mi!=0)
            {
                if(tp->mi==1)
                    printf("x");
                else
                    printf("x^%d",tp->mi);
            }
            else if(tp->xi==1||tp->xi==-1)
                printf("1");
 
        }
        tp=tp->next;
    }
    printf("\n");
}
void shuru(list *lp)
{
    list l;
    l = *lp;
    int xiangshu,mi,xi;
    printf("请输入多项式的项数： ");
    scanf("%d",&xiangshu);
    for(int i=1;i<=xiangshu;i++)
    {
        printf("请输入多项式的第%d项的系数和幂： ",i);
        scanf("%d%d",&xi,&mi);
        insert(&l,mi,xi);
    }
}
void start(list *Dxs1p,list *Dxs2p)
{
    list Dxs1,Dxs2;
    Dxs1 = *Dxs1p;
    Dxs2 = *Dxs2p;
    printf("第一个多项式，");
    shuru(&Dxs1);
    printf("输入的第一个多项式为： ");
    print_dxs(&Dxs1);
 
    printf("第二个多项式，");
    shuru(&Dxs2);
    printf("输入的第二个多项式为： ");
    print_dxs(&Dxs2);
}
int main()
{
    int choose;
    list *Dxs1,*Dxs2,*re1,*re2;
    Dxs1 = csh();
    Dxs2 = csh();
    re1 = csh();
    while(true)
    {
 
        clear(Dxs1);
        clear(Dxs2);
        clear(re1);
        printf("多项式相加请输入---1\n");
        printf("多项式相减请输入---2\n");
        printf("多项式相乘请输入---3\n");
        printf("退出---------------4\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            start(Dxs1,Dxs2);
            jia(Dxs1,Dxs2,re1);
            printf("两个多项式相加的结果： ");
            print_dxs(re1);
            break;
        case 2:
            start(Dxs1,Dxs2);
            jian(Dxs1,Dxs2,re1);
            printf("两个多项式相减的结果： ");
            print_dxs(re1);
            break;
        case 3:
            start(Dxs1,Dxs2);
            cheng(Dxs1,Dxs2,re1);
            printf("两个多项式相乘的结果： ");
            print_dxs(re1);
            break;
        case 4:exit(1);break;
        default:
            printf("错误！\n");
            break;
        }
    }
}
