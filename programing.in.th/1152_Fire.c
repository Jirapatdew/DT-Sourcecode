#include <stdio.h>
#include <stdlib.h>
int map[1010][1010]={0};
int data[10010]={0};
int find_maxx(int a)
{
    int i;
    for(i=a;i>=0;i--) if(data[i]!=0) return i;
    return 0;
}
int main()
{
    int i,j,sum=0,k,maxx=0;
    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) scanf("%d",&map[i][j]);
    //you can use heap but it will have more complexity
    for(k=n*2-1;k>=n+1;k--)
    {
        for(i=k-n+1,j=n;i<=n;i++,j--) {data[map[i][j]]++;if(map[i][j]>maxx)maxx=map[i][j];}
        sum+=maxx;
        data[maxx]--;
        maxx=find_maxx(maxx);
    }
    for(k=n;k>1;k--)
    {
        for(i=1,j=k;i<=n&&j>0;i++,j--) {data[map[i][j]]++;if(map[i][j]>maxx)maxx=map[i][j];}
        sum+=maxx;
        data[maxx]--;
        maxx=find_maxx(maxx);
    }
    printf("%d",sum);
    return 0;
}
