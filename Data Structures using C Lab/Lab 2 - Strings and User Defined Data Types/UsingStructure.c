#include <stdio.h>
struct student
{
    float p, c, m;
};

int main()
{
    int n, i;
    struct student s1[100];
    printf("\n enter number of student");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\n enter the marks for physics=");
        scanf("%f", &s1[i].p);
        printf("\n enter the marks for chemistry=");
        scanf("%f", &s1[i].c);
        printf("\n enter the marks for maths=");
        scanf("%f", &s1[i].m);
    }
    printf("\n marks are");
    for (i = 1; i <= n; i++)
        printf("%f\n%f\n%f\n", s1[i].p, s1[i].c, s1[i].m);
    return 0;
}
