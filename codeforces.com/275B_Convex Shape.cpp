#include <stdio.h>
#include <stdlib.h>

int main()
{
    char map[55][55];
    int sum;
    int i,j,k,l,p,n,m;
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++) gets(map[i]);
    sum=0;
    for(i=0;i<n;i++)
    {
        p=0;
        for(j=0;j<m;j++)
        {
            if(p==2&&map[i][j]=='B') {printf("NO");return 0;}
            else if(p==1&&map[i][j]=='W') p=2;
            else if(p==0&&map[i][j]=='B') p=1;
        }
    }
    for(j=0;j<m;j++)
    {
        p=0;
        for(i=0;i<n;i++)
        {
            if(p==2&&map[i][j]=='B') {printf("NO");return 0;}
            else if(p==1&&map[i][j]=='W') p=2;
            else if(p==0&&map[i][j]=='B') p=1;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=0;k<n;k++)
                for(l=0;l<m;l++)
                    if(map[i][j]=='B'&&map[k][l]=='B'&&map[i][l]=='W'&&map[k][j]=='W')
                        {printf("NO");return 0;}
    printf("YES");

    return 0;
}