#include <stdio.h>
#include <algorithm>
using namespace std;



struct dt
{
    int x,y;
}a[100050];
bool cmp(const dt& a,const dt& b)
{
        if(a.x!=b.x) return a.x<b.x;
        else return a.y<b.y;

};

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) printf("%d %d\n",a[i].x,a[i].y);
    return 0;
}
