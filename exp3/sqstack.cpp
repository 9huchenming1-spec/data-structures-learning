#include<stdio.h>
#include<malloc.h>
#define MAXSize 100
typedef char ElemType;
typedef struct{
    ElemType data[MAXSize];
    int top;
}SqStack;
void InitStack(SqStack *&s){
    s=(SqStack*)malloc(sizeof(SqStack));
    s->top=-1;
}
void DestroyStack(SqStack *&s){
    free(s);
}
bool StackEmpty(SqStack *s){
    return s->top==-1;
}
bool Push(SqStack *&s,ElemType e){
    if(s->top==MAXSize-1)
        return false;
    s->data[++s->top]=e;
    return true;
}
bool Pop(SqStack *&s,ElemType &e){
    if(s->top==-1)
        return false;
    e=s->data[s->top--];
    return true;
}
ElemType GetTop(SqStack *s){
    if(s->top==-1)
        return false;
    return s->data[s->top];
}