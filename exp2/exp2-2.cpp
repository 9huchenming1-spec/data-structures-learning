#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;
//头插
void CreatListF(LinkNode *&L,ElemType a[],int n)
{
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
//尾插
void CreatListR(LinkNode *&L,ElemType a[],int n)
{
    LinkNode *s, *r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
void InitList(LinkNode *&L)
{
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}
void DestroyList(LinkNode *&L)
{
    LinkNode *pre=L,*p=pre->next;
    while(p!=NULL){
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
bool ListEmpty(LinkNode *L)
{
    return(L->next==NULL);
}
int ListLength(LinkNode *L)
{
    int i=0;
    LinkNode *p=L;
    while (p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}
void DispList(LinkNode *L)
{
    LinkNode *p=L->next;
    while (p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType &e)
{
    int j=0;
    LinkNode *p=L;
    if(i<=0)return false;
    while (j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else{
        e=p->data;
        return true;
    }
}
int LocateList(LinkNode *L,ElemType e)
{
    int i=1;
    LinkNode *p=L->next;
    while (p!=NULL&&p->data!=e)
    {
        i++;
        p=p->next;
    }
    if(p==NULL) return 0;
    else return(i);
}
bool ListInsert(LinkNode *&L,int i,ElemType e)
{
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)return false;
    while (j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else{
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)return false;
    while (p!=NULL&&j<i-1)
    {
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else{
        s=p->next;
        if(s==NULL)return false;
        e=s->data;
        p->next=s->next;
        free(s);
        return true;
    }
}

int main()
{
    LinkNode *L;
    ElemType a[]={'a','b','c','d','e'};
    ElemType e;

    InitList(L);
    printf("初始化空表, 表长=%d, 是否为空=%d\n",ListLength(L),ListEmpty(L));

    DestroyList(L);

    CreatListR(L,a,5);
    printf("尾插法建表: ");
    DispList(L);
    printf("表长=%d\n",ListLength(L));

    ListInsert(L,3,'x');
    printf("在第3个位置插入'x': ");
    DispList(L);

    ListDelete(L,1,e);
    printf("删除第1个元素'%c': ",e);
    DispList(L);

    GetElem(L,2,e);
    printf("第2个元素是'%c'\n",e);
    printf("元素'c'的位置=%d, 元素'z'的位置=%d\n",LocateList(L,'c'),LocateList(L,'z'));

    DestroyList(L);

    CreatListF(L,a,5);
    printf("头插法建表: ");
    DispList(L);

    DestroyList(L);
    return 0;
}
