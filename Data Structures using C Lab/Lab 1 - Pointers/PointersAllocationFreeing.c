#include <stdio.h>
void circle(float k, float *x, float *y);
int main()
{
    float r, a, p;
    printf("\n enter the value for radius");
    scanf("%f", &r);
    circle(r, &a, &p);
    printf("\n area=%f", a);
    printf("\n perimeter=%f", p);
    return 0;
}

void circle(float k, float *x, float *y)
{
    *x = (3.14) * k * k;
    *y = 2 * 3.14 * k;
}
