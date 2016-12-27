#include <stdio.h>
#include <stdlib.h>

int A[100006]= {0};
int B[100006]= {0};
int n,k;
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int walk(int i,int a)
{
    if(i>n) return 0;
    if((-1*k)==a) return walk(i+1,a+1)+A[i];
    if(k==a) return walk(i+1,a-1)+B[i];
    if((-1*k)<a&&a<k) return min(walk(i+1,a+1)+A[i],walk(i+1,a-1)+B[i]);
}
int main()
{

    int i;
    int t,l;
    scanf("%d",&t);
    for(l=0; l<t; l++)
    {
        scanf("%d%d",&n,&k);
        for(i=1; i<=n; i++) scanf("%d%d",&A[i],&B[i]);
        printf("%d\n",walk(1,0));
    }

    return 0;
}
