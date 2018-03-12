#include <stdio.h>

int main()
{
    int *n;
    int i=2;
    printf("%d\n", i);
    n=&i;
    printf("%x\n", &i);
    printf("%x\n", n);
    printf("%d\n", *n);
    printf("%x\n", &n);
}
