#include <stdio.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
int a[100010][12]={0};
int b[12]={0};
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    vector<int> v;
    map<vector<int>,int> m;
    map<vector<int>,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        v.clear();
        for(int j=0;j<p;j++) {scanf("%d",&a[i][j]);v.push_back(a[i][j]);}
        m[v]=1;
    }
    for(int j=0;j<p;j++) scanf("%d",&b[j]);
    int i,j;
    for(i=0;i<=n;i++)
    {
        v.clear();
        for(j=0;j<p;j++) v.push_back(b[j]-a[i][j]);
        it=m.find(v);
        if(it!=m.end()) break;
    }
    if(i==n+1) printf("no");
    else printf("yes");
    return 0;
}
