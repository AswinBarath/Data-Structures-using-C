#include <stdio.h>
int n;
struct student
{
    int usn;
    char name[10];
    int sem;
};

int main()
{
    struct student s1[n];
    FILE *fp;
    fp = fopen("student.txt", "w");
    int i;
    printf("\n enter the number of student");
    scanf("\n %d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n enter the details");
        scanf("%d%s%d", &s1[i].usn, s1[i].name, &s1[i].sem);
        fprintf(fp, "%d%s%d", s1[i].usn, s1[i].name, s1[i].sem);
    }

    fclose(fp);
    fp = fopen("student.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d%s%d", &s1[i].usn, s1[i].name, &s1[i].sem);
        printf("%d%s%d", s1[i].usn, s1[i].name, s1[i].sem);
    }
    fclose(fp);
    return 0;
}
