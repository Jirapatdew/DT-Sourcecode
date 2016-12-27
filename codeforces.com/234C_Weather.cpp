#include <stdio.h>
#include <stdlib.h>
#define INF 2000000500
int plus[100500]={0};
int minus[100500]={0};
int main()
{
    int i,n,a,b;
    int min=INF;

    int zero=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        plus[i]=plus[i-1];
        minus[i]=minus[i-1];
        if(a>0) plus[i]++;
        else if(a<0) minus[i]++;
        else if(a==0) zero++;
    }
    for(i=1;i<n;i++)
    {
        b=plus[i]+minus[n]-minus[i]+zero;
        if(b<min) min=b;
    }
    printf("%d",min);
    return 0;
}