#include<stdio.h>
void f1();

void main()
{
    extern int a;
    printf("%d",a);
    f1();
    printf("Global var a=%d",a);
}
int a;
void f1()
{
    a = 10;
    printf("Global var a=%d",a);
}