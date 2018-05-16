#include <stdio.h>
#include <string.h>
/*  函数声明 */
int index(char *s, char *t, int pos);
void replace(char *s, char *t, char *v);
/*  主函数 */
int main()
{
    int k;
    char *s, t[] = "abc", *v = "%%%";
    s = (char *)malloc(100 * sizeof(char));
    printf("\n s=?");
    gets(s);
    printf("\n s=%s\n", s);
    printf("\n t=%s    v=%s\n", t, v);
    replace(s, t, v); /* 调用串置换函数 */
    printf("\n\n new string=%s\n", s);
} /* main   */
/*  串的置换，将主串s中的t串，置换为v串  */
void replace(char *s, char *t, char *v)
{
    int i, j, k, po, sl, tl;
    sl = strlen(s);
    tl = strlen(t);
    printf("\n sl=%d   tl=%d\n", sl, tl);
    po = 0;
    while (po < sl - tl + 1)
    {
        k = index(s, t, po); /* 调用串匹配函数 */
        printf("\n k=%2d", k);
        i = k - 1;
        for (j = 0; j <= tl - 1; j++)
        {
            s[i] = v[j];
            i++;
        }
        po = k + tl;
        printf("     pos=%2d", po);
    }
} /*  replace */
/*  串匹配函数 */
/*  从主串s的第pos个字符开始查找子串t，函数结果是子串t在主串s的pos开始之后首次出现的位置 */
int index(char *s, char *t, int pos)
{
    int i, j, sl, tl;
    i = pos;
    j = 1;
    sl = strlen(s);
    tl = strlen(t);
    while (i <= sl && j <= tl)
        if (s[i - 1] == t[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1 + 1;
            j = 1;
        }
    if (j > tl)
        return (i - tl);
    else
        return (-1);
} /*  index  */
