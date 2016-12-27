#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a(1005);
vector<int>::iterator it;
vector<int> minn(1005,1000000000);
int main()
{
    int n,k,m,x;
    int i,c,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        a[i]=c+a[i-1];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            x=a[j]-a[i-1];
            if(minn[j-i+1]>x) minn[j-i+1]=x;
        }
    }
    for(i=0;i<k;i++)
    {
        scanf("%d",&m);
        it=upper_bound(minn.begin()+1,minn.begin()+n+1,m);
        printf("%d\n",it-minn.begin()-1);

    }
    return 0;
}
