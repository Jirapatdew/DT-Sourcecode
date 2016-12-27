#include <stdio.h>
#include <stdlib.h>

//qsum 2d
int main()
{
    long **map=(long**)malloc(sizeof(long*)*1010);
    //long map[1100][1100];
    long n,m;
    //long ans[2000]={0};
    long x,y,k;
    long xc1,yc1,xc2,yc2;
    long i,j;
    long a,b,c,d;
    for(i=0; i<1010; i++) map[i]=(long*)malloc(sizeof(long)*1010);
    for(i=0; i<1010; i++)
        for(j=0; j<1010; j++) map[i][j]=0;
    scanf("%ld%ld",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%ld%ld",&x,&y);
        map[y][x]+=1;
    }
    for(i=0; i<1002; i++)
    {
        for(j=0; j<1002; j++)
        {
            map[i][j+1]+=map[i][j];
        }
    }
    for(i=0; i<1002; i++)
    {
        for(j=0; j<1002; j++)
        {
            map[j+1][i]+=map[j][i];
        }
    }
    for(i=0; i<m; i++)
    {
        scanf("%ld%ld%ld",&x,&y,&k);
        if(x+k>1001) xc1=1001;
        else xc1=x+k;
        if(y+k>1001) yc1=1001;
        else yc1=y+k;
        xc2=x-k-1;
        yc2=y-k-1;
        if(xc2<0&&yc2<0)
        {
            //printf("%d\n",map[yc1][xc1]);
            //ans[i]=map[yc1][xc1];
            printf("%ld\n",map[yc1][xc1]);
        }
        else if(xc2<0)
        {
            //printf("%d\n",map[yc1][xc1]-map[yc2][xc1]);
            //ans[i]=map[yc1][xc1]-map[yc2][xc1];
            printf("%ld\n",map[yc1][xc1]-map[yc2][xc1]);
        }
        else if(yc2<0)
        {
            //printf("%d\n",map[yc1][xc1]-map[yc1][xc2]);
            //ans[i]=map[yc1][xc1]-map[yc1][xc2];
            printf("%ld\n",map[yc1][xc1]-map[yc1][xc2]);
        }
        else
        {
            d=map[yc1][xc1];
            c=map[yc2][xc2];
            a=map[yc1][xc2];
            b=map[yc2][xc1];
           //printf("%d\n",d+c-a-b);
           //ans[i]=d+c-a-b;
           printf("%ld\n",d+c-a-b);
        }
        //printf("%ld\n",ans[i]);
    }
    //for(i=0; i<m; i++) printf("%ld\n",ans[i]);
    return 0;
}
