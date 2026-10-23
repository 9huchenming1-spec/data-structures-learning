
#include <stdio.h>
#include "sqstring.cpp"

// 求模式串 t 的 next 数组
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

// 显示匹配状态信息
void display(SqString s, SqString t, int i, int j)
{
    if (j == -1)
    {
        printf("主串指针位置:%d，模式串指针为-1，主串指针后移\n",
               i + 1);
    }
    else
    {
        printf("比较主串第%d个字符 '%c' 与模式串第%d个字符 '%c'\n",
               i + 1, s.date[i], j + 1, t.date[j]);
    }
}

// 利用 KMP 算法求模式串 t 在主串 s 中不重叠出现的次数
int Count(SqString s, SqString t)
{
    int next[MaxSize];
    int i = 0, j = 0;
    int count = 0;

    if (t.length == 0 || t.length > s.length)
        return 0;

    GetNext(t, next);

    while (i < s.length && j < t.length)
    {
        // 显示当前匹配状态
        display(s, t, i, j);

        if (j == -1 || s.date[i] == t.date[j])
        {
            i++;
            j++;

            // 模式串全部匹配成功
            if (j == t.length)
            {
                count++;

                printf("匹配成功！第%d次出现，起始位置为%d\n",
                       count, i - t.length + 1);

                // 关键：从主串当前位置继续，避免重叠匹配
                j = 0;
            }
        }
        else
        {
            j = next[j];
        }
    }

    return count;
}

int main()
{
    SqString s, t;
    char str[] = "aaaaa";
    char pat[] = "aa";

    // (1) 建立主串 s 和模式串 t
    StrAssign(s, str);
    StrAssign(t, pat);

    printf("主串 s:");
    DispStr(s);

    printf("模式串 t:");
    DispStr(t);

    // (2) 利用 KMP 算法统计不重叠出现次数
    printf("\n开始进行 KMP 匹配：\n");

    int count = Count(s, t);

    printf("\n子串 t 在主串 s 中不重叠出现的次数为:%d\n",
           count);

    DestroyStr(s);
    DestroyStr(t);

    return 0;
}
