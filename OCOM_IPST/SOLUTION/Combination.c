#include <stdio.h>
#include <stdlib.h>

int x[15]= {0},y=0;
int n,k,l;
int combination(int s,int p)
{
    int i,j;
    if(p>k)
    {
        y++;
        if(y==l) for(j=1; j<=k; j++) printf("%d ",x[j]);
        return 0;
    }
    else for(i=s; i<=n-(k-p); i++)
        {
            x[p]=i;
            combination(i+1,p+1);
        }
}
int main()
{
    scanf("%d%d%d",&n,&k,&l);
    combination(1,1);
    return 0;
}

/*      if(y==l) for(j=1;j<=k;j++) printf("%d ",x[j]);
*/
