#include <stdio.h>
#include <stdlib.h>

int ans[20]={0};
int val[2][20]={0};
int n;
double min=1000000000;
int bi(int a,int one)
{
    int i;
    double sum=0;
    if(a<=n)
    {
        for(i=0;i<2;i++)
        {
            ans[a]=i;
            bi(a+1,one+i);
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(ans[i]==1) sum+=val[1][i]-(val[1][i]*one/100.0);
            else sum+=val[0][i]-(val[0][i]*(n-one)/100.0);
        }
        if(min>sum) min=sum;
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&val[0][i]);
    for(i=1;i<=n;i++) scanf("%d",&val[1][i]);
    bi(1,0);
    printf("%.2lf",min);
    return 0;
}
