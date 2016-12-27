#include <stdio.h>
#include <math.h>
#define MIN(a,b) ((a<b)?a:b)
using namespace std;

int ab(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    int n,m;
    int sol[500][2]={0},k=0;
    scanf("%d%d",&n,&m);
    if(n==m) {printf("%d\n",n*2-1);}
    else {printf("%d\n",MIN(n,m)*2+ab(n-m)-1);}
    if(n!=m)
    {
        for(int i=1;i<=n&&i<=m;i++)
        {
            printf("%d %d\n",i,i);
            if(n<m) printf("%d %d\n",i,i+1);
            else printf("%d %d\n",i+1,i);
        }
        if(n<m) for(int i=n+2;i<=m;i++) printf("%d %d\n",n,i);
        else for(int i=m+2;i<=n;i++) printf("%d %d\n",i,m);
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            printf("%d %d\n",i,i);
            printf("%d %d\n",i,i+1);
        }
        printf("%d %d\n",n,n);
    }

    return 0;
}