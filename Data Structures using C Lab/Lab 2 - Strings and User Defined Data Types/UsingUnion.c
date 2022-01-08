#include <stdio.h>
#include <string.h>
union book
{
    int a;
    char name;
    //char author[20];
    float price;
};

int main()
{
    union book b1;
    printf("\n enter the integer value");
    scanf("%d", &b1.a);
    printf("\n%d", b1.a);
    printf("\n enter  the name of book");
    scanf("%c", &b1.name);
    printf(" %c", b1.name);
    printf("\n enter the price");
    scanf(" %f", &b1.price);
    printf("\n %f", b1.price);

    return 0;
}
