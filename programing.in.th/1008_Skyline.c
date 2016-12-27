#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,max=0,chk;
    int i,j;
    int l,h,r;
    int map[300]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&l,&h,&r);
        if(r>max) max=r;
        for(j=l;j<r;j++)
        {
            if(map[j]<h) map[j]=h;
        }
    }
    chk=0;
    for(i=0;i<=max;i++)
    {
        if(map[i]!=chk)
        {
            printf("%d %d ",i,map[i]);
            chk=map[i];
        }
    }
    return 0;
}
