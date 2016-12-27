#include <stdio.h>
#include <stdlib.h>
#define N 200
#define M 200
int main()
{
    int n,m,i,j,value_add[N][M]= {{0}},land[N][M]={{0}};
    int sumcl[M],sumrow[N],sumcl2[M],sumrow2[N];
    int total=0,max=0,after;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&land[i][j]);
            sumrow[i]+=land[i][j];
            sumcl[j]+=land[i][j];
            total+=land[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&value_add[i][j]);
            sumcl2[j]+=value_add[i][j];
            sumrow2[i]+=value_add[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        after=total-sumrow[i]+sumrow2[i+1]+sumrow2[i-1];
        if(after>max)
        {
            max=after;
        }
    }
    for(j=0; j<m; j++)
    {
        after=total-sumcl[j]+sumcl2[j+1]+sumcl2[j-1];
        if(after>max)
        {
            max=after;
        }
    }
    printf("%d",max);
        return 0;
    }
