
#include <stdio.h>
#include "sqstring.cpp"

int main()
{
    SqString s, s1, s2, s3, s4;
    char str[] = "abcdefghijklmn";
    char str1[] = "xyz";

    printf("顺序串的基本运算如下:\n");

    // (1) 建立串 s 和串 s1
    StrAssign(s, str);
    StrAssign(s1, str1);
    printf("(1)建立串s和串s1\n");

    // (2) 输出串 s
    printf("(2)输出串s:");
    DispStr(s);

    // (3) 输出串 s 的长度
    printf("(3)串s的长度:%d\n", StrLength(s));

    // (4) 在串 s 的第9个字符位置插入串 s1
    printf("(4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2 = InsStr(s, 9, s1);

    // (5) 输出串 s2
    printf("(5)输出串s2:");
    DispStr(s2);

    // (6) 删除串 s 从第2个字符开始的5个字符
    printf("(6)删除串s的第2个字符开始的5个字符而产生串s2\n");
    s2 = DelStr(s, 2, 5);

    // (7) 输出串 s2
    printf("(7)输出串s2:");
    DispStr(s2);

    // (8) 将串 s 从第2个字符开始的5个字符替换成串 s1
    printf("(8)将串s的第2个字符开始的5个字符替换成串s1而产生串s2\n");
    s2 = RepStr(s, 2, 5, s1);

    // (9) 输出串 s2
    printf("(9)输出串s2:");
    DispStr(s2);

    // (10) 提取串 s 从第2个字符开始的10个字符
    printf("(10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3 = SubStr(s, 2, 10);

    // (11) 输出串 s3
    printf("(11)输出串s3:");
    DispStr(s3);

    // (12) 连接串 s1 和串 s2
    printf("(12)将串s1和串s2连接起来而产生串s4\n");
    s4 = Concat(s1, s2);

    // (13) 输出串 s4
    printf("(13)输出串s4:");
    DispStr(s4);

    // 销毁顺序串
    DestroyStr(s);
    DestroyStr(s1);
    DestroyStr(s2);
    DestroyStr(s3);
    DestroyStr(s4);

    return 0;
}
