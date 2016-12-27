#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) (x>y)?x:y
using namespace std;

char a[1000050];
long long b[1000050][2]={0};
long long n,k,mx;
int cmp(const void*a,const void*b)
{
    long long *aa=(long long*)a;
    long long *bb=(long long*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='R') b[i][0]=b[i-1][0]-k;
        else b[i][0]=b[i-1][0]+1;
        b[i][1]=i;
    }
    qsort(b,n+1,sizeof(b[0]),cmp);
    int p=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i][0]==b[p][0]) mx=MAX(mx,b[i][1]-b[p][1]);
        else p=i;
    }
    printf("%lld",mx);
    return 0;
}
