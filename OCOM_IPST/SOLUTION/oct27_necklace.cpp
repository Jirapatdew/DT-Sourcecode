#include <stdio.h>
#include <string>
#include <list>

using namespace std;
list<int> l[300010];

int chk[300010]={0};

int recur(int i)
{
    printf("%d ",i);
    list<int>::iterator pt;
    for(pt=l[i].begin();pt!=l[i].end();pt++) recur(*pt);
    return 0;
}
int main()
{
    int n;
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        chk[a]=1;
        l[b].push_front(a);
    }
    int i;
    for(i=1;i<=n;i++) if(chk[i]==0) break;
    recur(i);
    return 0;
}
