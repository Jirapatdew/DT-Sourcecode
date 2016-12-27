#include <stdio.h>
#include <stdlib.h>

//use backtracking algorithm
int colum[10][10]= {0};
int row[10][10]= {0};
int box[4][4][10]= {0};
int map[10][10]= {0};

int walk(int a)
{
    int r,c,i,j;
    r=a/9;
    c=a%9;
    if(a==81)
    {
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++) printf("%d ",map[i][j]);
            printf("\n");
        }
        return 0;
    }
    if(map[r][c]!=0) walk(a+1);
    else
    {
        for(i=1; i<=9; i++)
        {
            if(row[r][i]==0&&colum[c][i]==0&&box[r/3][c/3][i]==0)
            {
                row[r][i]=1;
                colum[c][i]=1;
                box[r/3][c/3][i]=1;
                map[r][c]=i;
                walk(a+1);
                row[r][i]=0;
                colum[c][i]=0;
                box[r/3][c/3][i]=0;
                map[r][c]=0;
            }
        }
    }
}

int main()
{
    int i,j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]!=0)
            {
                colum[j][map[i][j]]++;
                row[i][map[i][j]]++;
                box[i/3][j/3][map[i][j]]++;
            }
        }
    }
    walk(0);
    return 0;
}
