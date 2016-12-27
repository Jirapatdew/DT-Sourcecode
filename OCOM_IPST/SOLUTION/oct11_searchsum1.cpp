#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a(100005);
vector<int>::iterator it;
int main()
{
    int n,k,m;
    int i,c;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        a[i]=c+a[i-1];
    }
    for(i=0;i<k;i++)
    {
        scanf("%d",&m);
        it=upper_bound(a.begin()+1,a.begin()+n+1,m);
        printf("%d\n",it-a.begin()-1);
    }
    return 0;
}
