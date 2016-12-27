#include <stdio.h>
#include <algorithm>
using namespace std;

int a[200010]={0};
int main()
{
    int n,m,k;
    int s,t,p;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&s,&t,&p);
        a[i]=s-t-p;
    }
    sort(a,a+n);
    int sum=m-1;
    for(int i=0;i<k;i++)
    {
        if(a[i]>0) break;
        else sum+=a[i];
    }
    printf("%d",sum);
    return 0;
}
