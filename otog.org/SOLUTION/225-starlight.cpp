#include <stdio.h>
#include <algorithm>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
#define MIN(_x,_y) ((_x)<(_y))?(_x):(_y)
using namespace std;

int main()
{
    int s,n;
    int x[5010]={0},y[5010]={0};
    scanf("%d%d",&s,&n);
    for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    x[n]=y[n]=0;
    sort(x,x+n+1);
    sort(y,y+n+1);
    double m1=x[0],m2=y[0],m;
    for(int i=1;i<=n;i++) m1=MAX((x[i]-x[i-1]),m1);
    for(int i=1;i<=n;i++) m2=MAX((y[i]-y[i-1]),m2);
    m1=MAX(s-x[n],m1);
    m2=MAX(s-y[n],m2);
    m=MIN(m1,m2);
    printf("%.3lf",m/2.0);
    return 0;
}
