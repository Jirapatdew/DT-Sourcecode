#include <stdio.h>
#include <stdlib.h>

int sequence[1002],A,B;
int distance[1002]={0};
int a[1002];
int b[1002];
int main()
{
    int i,j,n,m,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++) scanf("%d",&sequence[i]);
    for(i=0;i<m;i++)
    {
      scanf("%d",&distance[i]);
    }
    for(i=0;i<m-1;i++) a[i+1]=i;
    a[m-1]=0;
    for(i=1;i<m;i++) b[i]=i-1;
    a[0]=m-1;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&A,&B);
        j=sequence[0];
        while(1)
        {
            if(j==)
            j=a[j];
        }
        walk();

    }
    return 0;
}
void walk(int s,int t)
{

}
