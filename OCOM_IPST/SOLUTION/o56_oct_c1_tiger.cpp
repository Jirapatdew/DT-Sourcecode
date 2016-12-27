#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define ab(_x) (((_x)<0)?(-(_x)):(_x))
using namespace std;

int main()
{
    int n,m;
    int a[1000][2];
    int b[1000][2];
    int c[1000];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
    for(int i=0;i<m;i++) scanf("%d%d",&b[i][0],&b[i][1]);
    for(int i=0;i<m;i++) c[i]=-1u/2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[j]=MIN(c[j],ab(a[i][0]-b[j][0])+ab(a[i][1]-b[j][1]));
        }
    }
    sort(c,c+m);
    int tmp=-1u/2,num=0,mx=1;
    for(int i=0;i<m;i++)
    {
        if(tmp!=c[i]) {num=1;tmp=c[i];}
        else num++;
        mx=MAX(mx,num);
    }
    printf("%d",mx);
    return 0;
}
