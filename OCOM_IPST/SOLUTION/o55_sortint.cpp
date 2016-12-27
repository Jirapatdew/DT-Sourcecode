#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100050];
struct cmp
{
    bool operator() (const int& a,const int& b) const
    {
        return a<b;
    }
}cmp;
bool cmpclass(int a,int b)
{
    return a<b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) printf("%d\n",a[i]);
    return 0;
}
