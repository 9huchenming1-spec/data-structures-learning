#include<stdio.h>
#define MaxSize 100
typedef struct 
{
    char date[MaxSize];
    int length;
}SqString;
void StrAssign(SqString &s,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++){
        s.date[i]=cstr[i];
    }
    s.length=i;
}
void DestroyStr(SqString &s){
    s.length=0;
}
void StrCopy(SqString &s,SqString t){
    for(int i=0;i<t.length;i++){
        s.date[i]=t.date[i];
    }
    s.length=t.length;
}
bool StrEqual(SqString s,SqString t){
    if(s.length!=t.length){
        return false;
    }
    for(int i=0;i<s.length;i++){
        if(s.date[i]!=t.date[i]){
            return false;
        }
    }
    return true;
}
int StrLength(SqString s){
    return s.length;
}
SqString Concat(SqString s,SqString t){
    SqString st;
    st.length=s.length+t.length;
    for(int i=0;i<s.length;i++)st.date[i]=s.date[i];
    for(int i=0;i<t.length;i++)st.date[i+s.length]=t.date[i];
    return st;
}
SqString SubStr(SqString s,int i,int j){
    SqString str;
    int k;
    str.length=0;
    if(i<=0||i>s.length||j<0||i+j-1>s.length)return str;
    for(k=i-1;k<i+j-1;k++)str.date[k-i+1]=s.date[k];
    str.length=j;
    return str;
}
SqString InsStr(SqString s1,int i,SqString s2){
    int j;
    SqString str;
    str.length=0;
    if(i<0||i>s1.length+1)return str;
    for(j=0;j<i-1;j++)str.date[j]=s1.date[j];
    for(j=0;j<s2.length;j++)str.date[i+j-1]=s2.date[j];
    for(j=i-1;j<s1.length;j++)str.date[s2.length+j]=s1.date[j];
    str.length=s1.length+s2.length;
    return str;
}
SqString DelStr(SqString s,int i,int j){
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||i+j>s.length+1)return str;
    for(k=0;k<i-1;k++)str.date[k]=s.date[k];
    for(k=i+j-1;k<s.length;k++)str.date[k-j]=s.date[k];
    str.length=s.length-j;
    return str;
}
SqString RepStr(SqString s,int i,int j,SqString t){
    SqString str;
    int k;
    str.length;
    if(i<=0||i>s.length||i+j-1>s.length)return str;
    for(k=0;k<i-1;k++)str.date[k]=s.date[i];
    for(k=0;k<t.length;k++)str.date[k+i-1]=t.date[k];
    for(k=i+j-1;k<s.length;k++)str.date[k+t.length-j]=s.date[k];
    str.length=s.length-j+t.length;
    return str;
}
void DispStr(SqString s){
    if(s.length>0){
        for(int i=0;i<s.length;i++)printf("%c",s.date[i]);
        printf("\n");
    }
}