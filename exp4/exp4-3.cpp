
#include <stdio.h>
#include "sqstring.cpp"

// 简单模式匹配算法 BF
int Index(SqString s, SqString t)
{
    if (t.length == 0)
        return 1;

    int i = 0, j = 0;

    while (i < s.length && j < t.length)
    {
        if (s.date[i] == t.date[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j >= t.length)
        return i - t.length + 1;

    return 0;
}

// 求 next 数组
void GetNext(SqString t, int next[])
{
    int j = 0, k = -1;
    next[0] = -1;

    while (j < t.length - 1)
    {
        if (k == -1 || t.date[j] == t.date[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

// 求 nextval 数组
void GetNextval(SqString t, int nextval[])
{
    int j = 0, k = -1;
    nextval[0] = -1;

    while (j < t.length - 1)
    {
        if (k == -1 || t.date[j] == t.date[k])
        {
            j++;
            k++;

            if (t.date[j] != t.date[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
        {
            k = nextval[k];
        }
    }
}

// KMP 算法
int KMPIndex(SqString s, SqString t)
{
    int next[MaxSize];
    GetNext(t, next);

    int i = 0, j = 0;

    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.date[i] == t.date[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j >= t.length)
        return i - t.length + 1;

    return 0;
}

// 改进的 KMP 算法
int KMPIndex1(SqString s, SqString t)
{
    int nextval[MaxSize];
    GetNextval(t, nextval);

    int i = 0, j = 0;

    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.date[i] == t.date[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
    }

    if (j >= t.length)
        return i - t.length + 1;

    return 0;
}

int main()
{
    SqString s, t;
    char str[] = "abcabcdabcdeabcdefabcdefg";
    char pat[] = "abcdeabcdefab";

    int next[MaxSize];
    int nextval[MaxSize];

    // (1) 建立目标串 s 和模式串 t
    StrAssign(s, str);
    StrAssign(t, pat);

    printf("(1)目标串s:");
    DispStr(s);

    printf("   模式串t:");
    DispStr(t);

    // (2) 简单匹配算法
    printf("(2) BF算法匹配位置:%d\n", Index(s, t));

    // (3) 求 next 和 nextval 数组
    GetNext(t, next);
    GetNextval(t, nextval);

    printf("(3) next数组值:");
    for (int i = 0; i < t.length; i++)
        printf("%d ", next[i]);
    printf("\n");

    printf("    nextval数组值:");
    for (int i = 0; i < t.length; i++)
        printf("%d ", nextval[i]);
    printf("\n");

    // (4) KMP 算法
    printf("(4) KMP算法匹配位置:%d\n", KMPIndex(s, t));

    // (5) 改进的 KMP 算法
    printf("(5) 改进KMP算法匹配位置:%d\n", KMPIndex1(s, t));

    DestroyStr(s);
    DestroyStr(t);

    return 0;
}
