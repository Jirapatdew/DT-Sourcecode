#include <stdio.h>
#include <set>
using namespace std;
int ans[300010]={0};
set<int> a;
int main()
{
    int n,m;
    int l,r,x;
    set<int>::iterator low,up,pt;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) a.insert(i);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        low=a.lower_bound(l);
        up=a.upper_bound(r);
        while(low!=up)
        {
            pt=low;
            low++;
            if(*pt!=x) {ans[*pt]=x;
            a.erase(pt);}
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}
