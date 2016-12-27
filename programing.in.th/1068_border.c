#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int data[10005]={0};
    int map[205][205]={0};
    int n,k;
    int i,j,total=0;
    int t,u,p=0;
    scanf("%d%d",&n,&k);
    t=n*2;
    for(i=0;i<=t;i++)
    {
        if(i%2==0) u=n;
        else u=n+1;
        for(j=0;j<u;j++) scanf("%d",&map[i][j]);
    }
    for(i=1;i<=t;i+=2)
    {
        for(j=0;j<n;j++)
        {
            data[p]=(map[i][j]-map[i][j+1])*5+(map[i-1][j]-map[i+1][j])*3;
            p++;
        }
    }
    qsort(data,p,sizeof(data[0]),cmp);
    for(i=0;i<k;i++)
    {
        total+=data[i];
    }
    printf("%d",total);
    return 0;
}
