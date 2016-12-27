#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,x;
    int a[1010]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i]=x;
        for(int j=i;j>1;j--)
        {
            if(a[j]>=a[j-1])
            {
                swap(a[j-1],a[j]);
                if(a[j]!=a[j-1]) a[j-1]--;
                a[j]--;
                if(a[j]==-1)
                {
                    for(int k=i;k>0;k--)
                    {
                        if(x+i-k>a[k]) a[k]=x+i-k;
                        else break;
                    }
                }
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n",a[i]);
    return 0;
}
