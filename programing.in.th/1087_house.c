#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c,k,a,b;
    int i,j,t,sum,max;
    int data[305][305]={0};
    int q_row[305][305]={0};
    int q_col[305][305]={0};
    scanf("%d%d%d",&r,&c,&k);
    t=1;
    for(i=0;i<r;i++)
    {
        if(c%2==0) t=0-t;//*****************
        for(j=0;j<c;j++)
        {
            scanf("%d",&data[i][j]);
            t=0-t;
            data[i][j]*=t;
        }
    }
    for(i=0;i<r;i++)
    {
        q_row[i][0]=data[i][0];
        for(j=1;j<c;j++) q_row[i][j]=data[i][j]+q_row[i][j-1];
    }
    for(j=0;j<c;j++)
    {
        q_col[0][j]=data[0][j];
        for(i=1;i<r;i++) q_col[i][j]=data[i][j]+q_col[i-1][j];
    }

    t=1;
    for(i=0;i<r;i++)
    {
        if(c%2==0) t=0-t;//*****************
        for(j=0;j<c;j++)
        {
            sum=0;
            t=0-t;
            a=i+k;//col
            b=i-k;
            if(a>=r) a=r-1;
            if(b<0) b=0;
            sum+=q_col[a][j]-q_col[b][j]+data[b][j];
            a=j+k;//row
            b=j-k;
            if(a>=c) a=c-1;
            if(b<0) b=0;
            sum+=q_row[i][a]-q_row[i][b]+data[i][b];
            sum-=data[i][j];
            if(t==-1) sum*=-1;
            if(sum>max||(i==0&&j==0)) max=sum;
        }
    }
    printf("%d",max);
    return 0;
}
