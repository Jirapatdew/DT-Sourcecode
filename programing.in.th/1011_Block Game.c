#include <stdio.h>
#include <stdlib.h>

char map[6][6]= {'\0'};
char tmp;
int score=0;
int n,m;

int del(int x,int y)
{
    if(x<0||y<0) return 0;
    else if(x>=n||y>=m) return 0;
    if(map[x][y]!=tmp) return 0;
    else
    {
        score+=5;
        map[x][y]='-';
        del(x+1,y);
        del(x,y+1);
        del(x,y-1);
    }

}

int main()
{
    int i,j;
    int l,k,d=0;
    int x,y,nx,ny;
    char c,t;

    scanf("%d%d",&n,&m);
    scanf("\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%c",&map[i][j]);
            scanf("%c",&t);
        }
    }
    scanf("%d",&l);
    for(i=0; i<l; i++)
    {
        scanf("%d %d %c",&x,&y,&c);
        if(map[x][y]=='#'||map[x][y]=='-')
        {
            score-=5;
            continue;
        }
        else
        {
            nx=x;
            ny=y;
            if(c=='L')
            {
                if(y-1<0||map[x][y-1]!='-')
                {
                    score-=5;
                    continue;
                }
                else ny-=1;
            }
            else if(c=='R')
            {
                if(y+1>=m||map[x][y+1]!='-')
                {
                    score-=5;
                    continue;
                }
                else ny+=1;
            }
            map[x][ny]=map[x][y];
            //tmp=map[x][y];
            map[x][y]='-';
            /* for(j=x; j<n; j++)
             {
                 if(map[j][ny]!='-') break;
             }
             nx=j-1;
             map[nx][ny]=map[x][y];
             tmp=map[x][y];
             map[x][y]='-';*/
            while(1)
            {
                for(k=1; k<n; k++)
                {
                    for(j=0; j<m; j++)
                    {
                        if(map[k][j]=='-'&&map[k-1][j]!='-'&&map[k-1][j]!='#')
                        {
                            map[k][j]=map[k-1][j];
                            map[k-1][j]='-';
                            k=0;
                            break;
                        }
                    }
                }
                for(k=0; k<n; k++)
                {
                    for(j=0; j<m; j++)
                    {
                        tmp=map[k][j];
                        if(map[k][j]!='-'&&map[k][j]!='#')
                        if(map[k+1][j]==tmp||map[k][j+1]==tmp||map[k][j-1]==tmp)
                        {
                            del(k,j);
                            d=1;
                        }
                    }
                }
                if(d==1) {d=0;continue;}
                else break;
            }
        }
    }
    printf("%d\n",score);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
