#include <stdio.h>
#include <stdlib.h>

int n;
int map[20][20]= {0};
int cnt=0,tmp,total=0;

int chk(int x,int y)
{
    if(x<=0||y<=0) return 0;
    if(map[x][y]!=tmp) return 0;
    else
    {
        cnt++;
        map[x][y]=0;
        chk(x+1,y);
        chk(x,y+1);
        chk(x-1,y);
        chk(x,y-1);
    }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) scanf("%d",&map[i][j]);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(map[i][j]!=0)
            {
                tmp=map[i][j];
                if(map[i][j+1]==tmp&&map[i+1][j]==tmp) chk(i,j);
                else if(map[i+1][j]==tmp&&map[i+1][j-1]==tmp) chk(i,j);
                else if(map[i][j+1]==tmp&&map[i+1][j+1]==tmp) chk(i,j);
                else if(map[i+1][j]==tmp&&map[i+1][j+1]==tmp) chk(i,j);
                if(cnt==3) total++;
                cnt=0;
            }
        }
    }
   // for(i=1; i<=n; i++)
   //     {for(j=1; j<=n; j++) {printf("%d",map[i][j]);}printf("\n");}
   printf("%d",total);
    return 0;
}
