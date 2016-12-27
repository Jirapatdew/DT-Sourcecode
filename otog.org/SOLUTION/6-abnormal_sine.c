#include <stdio.h>
#include <stdlib.h>

int A(int n)
{
    //sin(1–sin(2+sin(3–sin(4+…sin(n))…)
    int i;
    for(i=1;i<n;i++)
    {
         printf("sin(");
         printf("%d",i);
         if(i%2==1) printf("-");
         else printf("+");
    }
    printf("sin(%d",n);
    for(i=1;i<=n;i++) printf(")");
}
int S(int n)
{
    int i;
    //(…(A1+n)A2+n–1)A3+…+2)An+1
    for(i=1;i<n;i++) printf("(");
    for(i=1;i<n;i++)
    {
        A(i);
        printf("+%d",n-i+1);
        printf(")");
    }
    A(n);
    printf("+1");
}
int main()
{
    int n;
    scanf("%d",&n);
    S(n);
    return 0;
}
