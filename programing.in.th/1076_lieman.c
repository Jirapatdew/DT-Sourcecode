#include <stdio.h>
#include <stdlib.h>

int data[30][30]= {0};
int tr[30]= {0};
int m,n,max=0;

int chk()
{
    int i,j,num=0;;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(data[i][j]==0) continue;
            if(data[i][j]!=tr[j]) {num--;break;}
        }
        num++;
    }
    return num;
}
int run(int p)
{
    int x;
    if(p==m)
    {
        x=chk();
        if(x>max) max=x;
        return 0;
    }
    if(tr[p]==0)
    {
        tr[p]=1;
        run(p+1);
        tr[p]=-1;
        run(p+1);
        tr[p]=0;
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d",&data[i][j]);
    run(0);
    printf("%d",n-max);
    return 0;
}
