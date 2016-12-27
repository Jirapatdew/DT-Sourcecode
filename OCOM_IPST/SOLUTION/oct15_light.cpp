#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[100010][2]={0},sz=0;
int b[100010]={0};
int cmp(const void*A,const void*B)
{
    int *aa=(int*)A;
    int *bb=(int*)B;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[sz][0],&a[sz+1][0]);
        a[sz][1]=1;
        a[sz][0]++;
        a[sz+1][1]=-1;
        sz+=2;
    }
    qsort(a,sz,sizeof(a[0]),cmp);
    int i=0,j;
    for(j=1;j<sz;j++)
    {
        if(a[j][0]==a[i][0]) a[i][1]+=a[j][1];
        else
        {
            a[++i][0]=a[j][0];
            a[i][1]=a[j][1]+a[i-1][1];
        }
    }
    sz=i+1;
    int x,sum=0;
    int *pt;
    for(int i=0;i<sz;i++) b[i]=a[i][0];
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        pt=upper_bound(&b[0],&b[sz],x);
        if(pt!=b)
        {
            pt--;
            sum+=a[pt-b][1];///***///
            sum%=2007;
        }
    }
    printf("%d",sum%2007);
    return 0;
}
