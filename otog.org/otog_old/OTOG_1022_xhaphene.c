#include <stdio.h>
#include <stdlib.h>

int mid;
int data[10005][2]={0};
int find(int idx,int a,int p)
{
    if(a==mid)
    {
        printf("%d",idx);
        return 0;
    }
    if(data[idx][0]!=p) find(data[idx][0],a+1,idx);
    else find(data[idx][1],a+1,idx);
}
int main()
{
    int n,i,a,b;
    int len[10005]={0};
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        data[a][len[a]++]=b;
        data[b][len[b]++]=a;
    }
    for(i=1;i<=n;i++) if(len[i]==1) break;
    mid=n/2+1;
    find(i,1,i);
    return 0;
}
