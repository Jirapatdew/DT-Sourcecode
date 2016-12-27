#include <stdio.h>
#include <stdlib.h>

int data[1000010]={0};
int main()
{
    int n,max,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    max=data[1];
    for(i=2;i<=n;i++) data[i]=(data[i]>data[i]+data[i-1])?data[i]:data[i]+data[i-1];
    for(i=2;i<=n;i++) if(data[i]>max) max=data[i];
    printf("%d",max);
    return 0;
}
