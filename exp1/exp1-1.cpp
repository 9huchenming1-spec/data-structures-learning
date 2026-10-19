//——————实验题一————————————————————————————————————————————————
#include<stdio.h>
#include<time.h>
#include<math.h>
typedef long ElemType;

ElemType fun1(ElemType n){
    ElemType sum=0,i;
    for(i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}

void Time1(ElemType n){
    clock_t t;
    ElemType sum;
    t=clock();
    sum=fun1(n);
    t=clock()-t;
    printf("方法1：\n");
    printf("结果：1~%d的和：%d\n",n,sum);
    printf("用时：%lf秒\n",((float)t)/CLOCKS_PER_SEC);
}
ElemType fun2(ElemType n){
    return n*(n+1)/2;
}
void Time2(ElemType n){
    clock_t t;
    ElemType sum;
    t=clock();
    sum=fun2(n);
    t=clock()-t;
    printf("方法2：\n");
    printf("结果：1~%d的和：%d\n",n,sum);
    printf("用时：%lf秒\n",((float)t)/CLOCKS_PER_SEC);
}

int main(){
    ElemType n;
    printf("n(大于1000000)：");
    scanf("%d",&n);
    if(n<1000000) return 0;
    Time1(n);
    Time2(n);
    return 1;
}
