/*
Linked list -- you don't need to know how many 
thing will be stored

*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;
// What does this do

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        RDisplay(p->next);
        printf("%d ",p->data);

    }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
        {
            l++;
            p=p->next;
        }
    return l;
}

int Rcount(struct Node *p)
{
    if(p!=NULL)
        // addition will be done at returning time not call (0+1)
        // recursive is costly in space
        return Rcount(p->next)+1;
    else
        return 0;
}

int sum(struct Node *p)
{
    int s=0;

    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next)+p->data;
}

// assuming this is the smallest int number
int INT32_MIN =-32768;

int Max(struct Node *p)
{
    int max=INT32_MIN;

    while(p)
    {
    if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;

}
int RMax(struct Node *p)
{
    int x=0;

    if(p==0)
        return INT32_MIN;
    x=RMax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}

struct Node * LSearch(struct Node *p,int key)
{
    struct Node *q;

    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;

}
struct Node * RSearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);

}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }

}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;

    }
}

int isSorted(struct Node *p)
{
    int x=-65536;
    
    while(p!=NULL)
    {
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;

}

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index < 1 || index > count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;

    }
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }

}

void Reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;

    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}
void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}
void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    struct Node *third;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;

        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;

        }
    }
    if(p)last->next=p;
    if(q)last->next=q;

}

int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}

/*Circular LL*/

struct CircNode
{
    int data;
    struct Node *next;
}*Head;

int Length(struct CircNode *p)
{
    int len=0;
    
    do
    {
    len++;
    p=p->next;
    }while(p!=Head);
    return len;
}
void Insert(struct CircNode *p,int index, int x)
{
    struct CircNode *t;
    
    int i;
    if(index<0 || index > Length(p))
        return;

    if(index==0)
    {
        t=(struct CircNode *)malloc(sizeof(struct CircNode));
        t->data=x;
        if(Head==NULL)
        {
            Head=t;
            Head->next=Head;
        }
        else
        {
            while(p->next!=Head)p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }

    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
        t=(struct CircNode *)malloc(sizeof(struct CircNode));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}
int Delete(struct CircNode *p,int index)
{
    struct CircNode *q;
    int i,x;

    if(index <0 || index >Length(Head))
        return -1;
    if(index==1)
    {
        while(p->next!=Head)p=p->next;
        x=Head->data;
        if(Head==p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
            q=p->next;
            p->next=q->next;
            x=q->data;
            free(q);
    }
    return x;
}



int main()
{
    struct Node *temp;
    int A[]={3,5,7,10,25,8,32,2};
    create(A,8);

    Display(first);

    return 0;
}

// finding the intersection of two linked lists
// work backwards from the end of linked list using the stack
// find the last node where the linked lists are the same

/*
sparse matrix and polynomial using linked lists

use it like a hash table - you can easily add two sparse matrices


*/

#include <math.h>
struct PolyNode
{
    int coeff;
    int exp;
    struct PolyNode *next;
}*poly=NULL;

void creatPoly()
{
    struct PolyNode *t,*last=NULL;
    int num,i;

    printf("Enter number of terms");
    scanf("%d",&num);
    printf("Enter each term with coeff and exp\n");

    for(i=0;i<num;i++)
    {
        t=(struct PolyNode *)malloc(sizeof(struct PolyNode));
        scanf("%d%d",&t->coeff,&t->exp);
        t->next=NULL;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
}
void Display(struct PolyNode *p)
{
    while(p)
    {
        printf("%dx%d +",p->coeff,p->exp);
        p=p->next;
    }
    printf("\n");
}
long Eval(struct PolyNode *p, int x)
{
    long val=0;

    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}
int mainPoly()
{
    createPoly();
    Display(poly);
    printf("%ld\n",Eval(poly,1));
    return 0;
}