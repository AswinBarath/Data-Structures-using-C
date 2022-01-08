#include <stdio.h>
#include <string.h>
int strl(char a[100])
{
    int n = 0, i;
    for (i = 0; a[i] != '\0'; i++)
        n++;
    return n;
}

void strc(char a[100], char b[100])
{
    int n, i, j;
    n = strlen(a);
    for (i = n, j = 0; b[j] != '\0'; i++, j++)
        a[i] = b[j];
    a[i] = '\0';
    puts(a);
}

int strcm(char a[100], char b[100])
{
    int i, flag = 0;
    for (i = 0; (a[i] != '\0') && (b[i] = '\0'); i++)
    {
        if (b[i] == a[i] && a[i] != '\0' && b[i] != '\0')
            flag = 1;
        else
            flag = 0;
        return flag;
    }
}

void strcp(char b[100])
{
    char c[100];
    int i;
    for (i = 0; b[i] != '\0'; i++)
        c[i] = b[i];
    c[i] = '\0';
    puts(c);
}

void strr(char a[100])
{
    char b[100];
    int i, j, n;
    n = strl(a);
    for (i = n - 1, j = 0; i >= 0; i--, j++)
        b[j] = a[i];
    b[j] = '\0';
    puts(b);
}

int strst(char a[100], char b[100])
{
    int i, j = 0, n, flag = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        n = i;
        for (j = 0; b[j] != '\0'; j++)
        {
            if (a[n] == b[j])
            {
                flag = 1;
                n++;
            }
            else
            {
                flag = 0;
                break;
            }
            if (flag)
                break;
        }
    }
    return flag;
}

void main()
{
    char a[100], b[100];
    printf("enter the string");
    gets(a);
    gets(b);
    printf("string length=%d", strl(a));
    printf("string compare=%s\n", strcm(a, b) ? "true" : "false");

    printf("string cat=");
    strc(a, b);

    printf("string sub string=%d", strst(a, b));
    printf("string rev=");
    strr(a);
}
