#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct 
{
    double coef;
    int expn;
}PolyArray;
typedef struct pnode
{
    double coef;
    int expn;
    struct pnode *next;
}PolyNode;
void DispPoly(PolyNode *L)
{
    bool first=true;
    PolyNode *q=L->next;
    while(q!=NULL)
    {
        if(first)
        {
            first=false;
        }
        else if(q->coef>0)
        {
            printf("+");
        }
        if (q->expn==0)
        {
            printf("%g",q->coef);
        }
        else if(q->expn==1)
        {
            printf("%gx",q->coef);
        }
        else
        {
            printf("%gx^%d",q->coef,q->expn);
        }
        q=q->next;
    }
    printf("\n");
}
void DestroyPoly(PolyNode *&L)
{
    PolyNode *pre=L,*q=pre->next;
    while(q!=NULL)
    {
        free(pre);
        pre=q;
        q=q->next;
    }
    free(pre);
}
void CreatePoly(PolyNode *&L,PolyArray a[],int n)
{
    PolyNode *s,*r;
    int i;
    L=(PolyNode *)malloc(sizeof(PolyNode));
    L->next=NULL;
    r=L;
    for(i=0;i<n;i++)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));
        s->coef=a[i].coef;
        s->expn=a[i].expn;
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
void Sort(PolyNode *&L)
{
    PolyNode *p=L->next,*pre,*q;
    if(p!=NULL){
        q=p->next;
        p->next=NULL;
        p=q;
        while(p!=NULL)
        {
            q=p->next;
            pre=L;
            while(pre->next!=NULL&&pre->next->expn> p->expn)
            {
                pre=pre->next;
            }
            p->next=pre->next;
            pre->next=p;
            p=q;
        }
    }
}
void Add(PolyNode *&ha,PolyNode *hb,PolyNode *&hc)
{
    PolyNode *pa=ha->next,*pb=hb->next,*s,*r;
    double c;
    hc=(PolyNode *)malloc(sizeof(PolyNode));
    hc->next=NULL;
    r=hc;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->expn>pb->expn)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode));
            s->coef=pa->coef;
            s->expn=pa->expn;
            r->next=s;
            r=s;
            pa=pa->next;
        }
        else if(pa->expn<pb->expn)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode));
            s->coef=pb->coef;
            s->expn=pb->expn;
            r->next=s;
            r=s;
            pb=pb->next;
        }
        else
        {
            c=pa->coef+pb->coef;
            if(c!=0)
            {
                s=(PolyNode *)malloc(sizeof(PolyNode));
                s->coef=c;
                s->expn=pa->expn;
                r->next=s;
                r=s;
            }
            pa=pa->next;
            pb=pb->next;
        }
    }
    while(pa!=NULL)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));
        s->coef=pa->coef;
        s->expn=pa->expn;
        r->next=s;
        r=s;
        pa=pa->next;
    }
    while(pb!=NULL)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));
        s->coef=pb->coef;
        s->expn=pb->expn;
        r->next=s;
        r=s;
        pb=pb->next;
    }
    r->next=NULL;
}
int main()
{
    PolyNode *ha,*hb,*hc;
    PolyArray a[]={{3,4},{2,3},{1,2},{-1,0}};
    PolyArray b[]={{5,3},{-2,2},{1,0}};
    CreatePoly(ha,a,4);
    CreatePoly(hb,b,3);
    Sort(ha);
    Sort(hb);
    Add(ha,hb,hc);
    DispPoly(hc);
    DestroyPoly(ha);
    DestroyPoly(hb);
    DestroyPoly(hc);
    return 0;
}
