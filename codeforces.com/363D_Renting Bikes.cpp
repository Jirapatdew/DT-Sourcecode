#include <stdio.h>
#include <algorithm>
#define INF (-1u/2)
using namespace std;
int b[100010]={0};
int p[100010]={0};
int mem[100010]={0};
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    sort(b+1,b+n+1,cmp);
    sort(p+1,p+m+1);
    int lo=0,hi=min(n,m),s=0,x;
    while(lo<hi)
    {
        int mid=(lo+hi+1)/2,num=0;
        x=a;
        s=0;
        num=0;
        for(int i=1;i<=mid;i++)
        {
            if(b[i]>=p[mid-i+1]) {num++;s+=p[mid-i+1];}
            else if(x-(p[mid-i+1]-b[i])>=0)
            {
                x-=(p[mid-i+1]-b[i]);
                num++;
                s+=b[i];
            }
            else break;
        }
        if(num<mid) hi=mid-1;
        else lo=mid;
        if(x>0) s-=x;
        if(s<0) s=0;
        mem[mid]=s;
    }
    printf("%d %d",lo,mem[lo]);
    return 0;
}