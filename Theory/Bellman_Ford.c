#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,n,a,v;
    int G[100][100][2]= {0},p[100]= {0},x[100]= {0};
    int d[100]= {0},hp[100]= {0};
    scanf("%d%d",&v,&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        scanf("%d%d",&G[a][x[a]][0],&G[a][x[a]][1]);//[1]=ÃÐÂÐ [0] =»Á
        x[a]++;
    }
    for(i=0; i<=v; i++) d[i]=2000000000;
    d[1]=0;//d[1] to d[v]
    for(i=0; i<v; i++)
    {
        for(j=1; j<=v; j++)
        {
            for(k=0; k<x[a]; k++)
            {
                if(d[j]+G[j][k][1]<d[G[j][k][0]])
                {
                    d[G[j][k][0]]=d[j]+G[j][k][1];
                    p[G[j][k][0]]=j;
                }
            }
        }
    }

    for(j=1; j<=v; j++) //àªç¤
        for(k=0; k<x[a]; k++)
            if(d[j]+G[j][k][1]<d[G[j][k][0]])
            {
                printf("Negative-weight cycle");
            }

    for(i=1; i<=v; i++) printf("p[%d] = %d\n",i,p[i]);
    for(i=1; i<=v; i++) printf("d[%d] = %d\n",i,d[i]);
    return 0;
}
/*
7 12
1 3 3
1 4 4
2 1 6
2 4 8
3 4 7
3 6 12
4 5 0
4 6 5
5 2 10
5 7 3
6 5 1
6 7 2
*/

