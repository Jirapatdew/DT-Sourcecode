#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int n;
    int i;
    int val[100010]={0};
    int P[100010]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&val[i]);
    for(i=3;i<=n;i++)
    {
        P[i]=max(P[i-3]+val[i],P[i-1]);
    }
    printf("%d",P[n]);
    return 0;
}
/*
P(i)=  max(P(i-3)+val[i],P(i-1))    if i>3
    =  0                            if i<3
*/
