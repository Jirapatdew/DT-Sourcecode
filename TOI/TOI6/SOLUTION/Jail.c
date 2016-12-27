/*
TASK: Jail
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,st=1,i=0,j,s=0;
    int* x;
    x = malloc(sizeof(int)*1000001);
    scanf("%d%d",&n,&m);
    for(j=1;i<n;j++)
    {
        if(j>n) j=1;
        if(x[j]==0) s++;
        if(s==m)
        {
            x[j]=1;
            i++;
            printf("%d ",j);
            s=0;
        }
    }
    return 0;
}
/*  int* x;
    x = malloc(sizeof(int)*1000001);
*/
