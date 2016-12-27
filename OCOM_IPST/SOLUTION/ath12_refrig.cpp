#include <stdio.h>

using namespace std;

int main()
{
    int t,n,i;
    int min=-1u/2;
    int a[1000]={0};
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        int sum=0;
        min=-1u/2;
        while(1)
        {
            for(i=0;i<n;i++) if(a[i]<min) min=a[i];
            if(min==0) break;
            for(i=0;i<n;i++) if(a[i]==min) break;   else a[i]--;
            for(i=i+1;i<n;i++) a[i]--;
            sum++;
        }
        printf("%d\n",sum);
        t--;
    }
    return 0;
}
