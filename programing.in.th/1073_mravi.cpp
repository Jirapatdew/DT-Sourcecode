#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,t,x,c,te;
    char D[2];
    int a[100000]={0};
    scanf("%d%d",&n,&t);
    scanf("%d",&c);
    t%=(2*n);
    te=t;
    for(int i=0;i<c;i++)
    {
        t=te;
        scanf("%d%s",&a[i],D);
        if(D[0]=='L')
        {
            if(t<=a[i]) a[i]-=t;
            else
            {
                t-=a[i];
                a[i]=0;
                if(t<=n-a[i]) a[i]+=t;
                else
                {
                    t-=n-a[i];
                    a[i]=n-t;
                }
            }
        }
        else
        {
            if(t<=n-a[i]) a[i]+=t;
            else
            {
                t-=n-a[i];
                a[i]=n;
                if(t<=a[i]) a[i]-=t;
                else
                {
                    t-=a[i];
                    a[i]=t;
                }
            }
        }
    }
    sort(a,a+c);
    for(int i=0;i<c;i++) printf("%d ",a[i]);
    return 0;
}
