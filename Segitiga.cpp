#include <stdio.h>
int main ()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a >= b + c) || (b >= a + c) || (c >= a + b))
        printf("Bukan segitiga");
    else 
        if ((a == b) && (b == c))
        printf("Segitiga sama sisi");
    else 
        if ((a == b) || (b == c) || (a == c)) {
        printf("Segitiga sama kaki");
    } else
        printf("Segitiga sembarang");
       
    return 0;
}