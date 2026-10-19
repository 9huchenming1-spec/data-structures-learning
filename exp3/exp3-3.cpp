#include<stdio.h>
#include<malloc.h>
#include"sqqueue.cpp"
 
int main(){
    SqQueue *q;
    InitQueue(q);
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    ElemType e;
    deQueue(q,e);
    printf("出队<1>:\n%c\n",e);
    enQueue(q,'d');
    enQueue(q,'e');
    enQueue(q,'f');
    printf("出队<2>:\n");
    while(!QueueEmpty(q)){
        deQueue(q,e);
        printf("%c\n",e);
    }
    DestroyQueue(q);
}