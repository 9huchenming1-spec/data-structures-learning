#include"sqstack.cpp"
int main(){
    ElemType e;
    SqStack *s;
    InitStack(s);
    printf("初始化栈s:\n");
    printf("栈为%s\n",StackEmpty(s)?"空":"非空");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("栈为%s\n",StackEmpty(s)?"空":"非空");
    printf("出栈序列：");
    while (!StackEmpty(s)) {
        Pop(s, e);
        printf("%c ", e);
    }
    printf("\n");
    printf("栈为%s\n",StackEmpty(s)?"空":"非空");;
    printf("释放栈s\n");
    DestroyStack(s);
    return 0;
}