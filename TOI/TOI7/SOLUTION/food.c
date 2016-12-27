/*
TASK: food
LANG: C
AUTHOR: Jirapat Atiwattanachai
CENTER: KKU03
*/
#include <stdio.h>
#include <stdlib.h>

int in,j;
int h[10]={0};
int chk[10]={0};
int ans[10]={0};

int permul(int N)
{
    int a;
    if(N<=in)
    {
        for(a=1;a<=in;a++)
        {
            if(chk[a]==0)
            {
               chk[a]=1;
               ans[N]=a;
               permul(N+1);
               chk[a]=0;
            }
        }
    }
    else if(h[ans[1]]==0)
    {
        for(j=1;j<=in;j++) printf("%d ",ans[j]);
        printf("\n");
    }
}
int main()
{
    int m,i,k;
    scanf("%d",&in);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        h[k]=1;
    }
    permul(1);
    return 0;
}
