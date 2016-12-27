#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k,temp=0,c;
    int i,j;
    int a,b;
    int x,y;
    int data[105][105][2]={{{0}}};
    scanf("%d%d%d",&m,&n,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) scanf("%d",&data[i][j][0]);
    for(c=1;c<=k;c++)
    {
        scanf("%d%d",&b,&a);
        x=a;
        y=b;
        while(1)
        {
            if(data[x][y][1]==1) {printf("NO\n");break;}
            if(data[x][y][0]==0)
            {
                if(temp==1) printf("N\n");
                else if(temp==2) printf("E\n");
                else if(temp==3) printf("S\n");
                else if(temp==4) printf("W\n");
                break;
            }
            else if(data[x][y][0]==1) {data[x][y][1]=1;temp=1;x--;}
            else if(data[x][y][0]==2) {data[x][y][1]=1;temp=2;y++;}
            else if(data[x][y][0]==3) {data[x][y][1]=1;temp=3;x++;}
            else if(data[x][y][0]==4) {data[x][y][1]=1;temp=4;y--;}
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++) data[i][j][1]=0;
    }
    return 0;
}
