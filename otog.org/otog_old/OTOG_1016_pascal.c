#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r,i,j,x,y;
    long long total=2;
    long long data[2][1010]={0};
    scanf("%d%d",&n,&r);
    data[0][0]=1;
    for(i=0;i<n;i++)
    {
        x=i%2;
        y=(i+1)%2;
        for(j=0;j<=i+1;j++) data[y][j]=0;
        for(j=0;j<=i;j++)
        {
            data[y][j]+=data[x][j];
            data[y][j+1]+=data[x][j];
        }
        for(j=0;j<=i+1;j++) data[y][j]%=100000;
    }
    printf("%d",data[n%2][r]);
    return 0;
}
