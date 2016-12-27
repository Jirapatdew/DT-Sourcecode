#include <stdio.h>
#include <stdlib.h>

int data[1000005]={0};
int main()
{
    int n,k;
    int i,j,max;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        data[i]+=data[i-1];
    }
    max=data[k];
    for(i=0,j=k;j<=n;i++,j++)
    {
        if(data[j]-data[i]>max) max=data[j]-data[i];
    }
    printf("%d",max);
    return 0;
}
