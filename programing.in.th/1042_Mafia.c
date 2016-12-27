#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k,x,y,r;
    int i,j,data_x[5001]={0},data_y[5001]={0},max=0,s1,s2,s3,s4,s5;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d%d",&x,&y,&r);
        s1=(x-r>-1)?x-r:0;
        s2=(x+r<5001)?x+r:5000;
        for(j=s1;j<=s2;j++)
        {
            ++data_x[j];
        }
        s3=(y-r>-1)?y-r:0;
        s4=(y+r<5001)?y+r:5000;
        for(j=s3;j<=s4;j++)
        {
            ++data_y[j];
        }
    }
    s5=(m>n)?m:n;
    for(i=0;i<=s5;i++)
    {
        if(max<data_x[i]&&i<=m) max=data_x[i];
        if(max<data_y[i]&&i<=n) max=data_y[i];
    }
    printf("%d",max);
    return 0;
}
