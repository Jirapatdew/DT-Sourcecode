#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i,x;
    int data[2000001]={0};
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) {scanf("%d",&x);data[x]=1;}
    for(i=2000000;k>0;i--)
    {
        if(data[i]==1) k--;
    }
    printf("%d",i+1);
    return 0;
}
