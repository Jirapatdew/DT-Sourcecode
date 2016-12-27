#include <stdio.h>
#include <set>
using namespace std;

struct dt
{
    int a,b;
};
struct cmpclass
{
    bool operator () (const dt& aa,const dt& bb) const
    {
        if(aa.a!=bb.a) return aa.a<bb.a;
        else return aa.b>bb.b;
    }
};
multiset<dt,cmpclass> ST;
int main()
{
    int n,m;
    char ch[10];
    dt x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n+m;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='T')
        {
            scanf("%d%d",&x.a,&x.b);
            ST.insert(x);
        }
        else if(!ST.empty())
        {
            printf("%d\n",ST.begin()->b);
            ST.erase(ST.begin());
        }
        else printf("0\n");

    }
    return 0;
}
