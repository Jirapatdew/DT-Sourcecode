#include <stdio.h>
#include <stdlib.h>

int map[5005]={0};
int main()
{
    int h,l,n;
    int i,x,max=0;
    scanf("%d%d%d",&h,&l,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        map[x]++;
    }
    for(i=l;i<=l+h;i++)
    {
        if(map[i]>max) max=map[i];
    }
    printf("%d",max);
    return 0;
}
