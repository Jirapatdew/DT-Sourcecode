#include <stdio.h>
#include <set>
#include <vector>
#include <map>
using namespace std;

struct dt
{
    int w,v;
    bool operator < (const dt &T) const
    {
        return w<T.w;
    }
    dt(int a,int b)
    {
        w=a;
        v=b;
    }
};
struct vec
{
    int w,c,x;
};
set<dt> hat;
map<int ,vector<vec> > chk;
int main()
{
    int n,m;
    int T,c,w,v,d,x;
    vec tmp;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n+m; i++)
    {
        int siz = chk[i].size();
        for(int j=0; j<siz; j++)
        {
            set<dt>::iterator pt;
            int a=chk[i][j].w,b;
            pt=hat.lower_bound(dt(a,0));
            if(pt==hat.end()||pt->w!=a) continue;
            b=pt->v;
            hat.erase(pt);
            if(chk[i][j].c==3) hat.insert(dt(chk[i][j].x,b));
        }
        /////
        scanf("%d",&T);
        if(T==1)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d%d",&w,&v);
                hat.insert(dt(w,v));
            }
            else
            {
                scanf("%d%d%d",&w,&v,&d);
                if(c==3)
                {
                    scanf("%d",&x);
                    tmp.x=x;
                }
                tmp.w=w;
                tmp.c=c;
                if(d!=i)
                {
                    hat.insert(dt(w,v));
                    chk[d].push_back(tmp);
                }
                else if(c==3) hat.insert(dt(x,v));

            }
        }
        else
        {
            if(hat.empty()) printf("0\n");
            else
            {
                printf("%d\n",hat.begin()->v);
                hat.erase(hat.begin());
            }

        }
    }
    return 0;
}
