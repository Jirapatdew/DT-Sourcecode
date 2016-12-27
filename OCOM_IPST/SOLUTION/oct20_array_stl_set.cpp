#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;
typedef struct tree
{
    int x;
    int y;
    bool operator<(const struct tree &T) const
    {
        //if(x == T.x) return y < T.y;
        return x<T.x;
    };
} tree;
set<tree> data;
/*void update(int idx ,int val,int MaxVal)
{
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}*/
int main()
{
    int i,j,a;
    int n,q,x[3];
    set<tree>::iterator it;
    set<tree>::iterator fi;
    tree z,tmp;
    z.x=0;
    z.y=0;
    data.insert(z);
    scanf("%d%d",&n,&q);
    for(i=0; i<q; i++)
    {
        scanf("%d",&a);
        if(a==0)
        {
            scanf("%d%d%d",&x[0],&x[1],&x[2]);
            for(j=0; i<2; j++)
            {
                tmp.x=x[j]+j;
                fi=data.find(tmp);
                it=data.end();
                if(fi==data.end())
                {
                    z.y=x[2];
                    z.x=tmp.x;
                    data.insert(z);
                }
                else
                {
                    z.y=x[2]+(*fi).y;//fi->y
                    z.x=tmp.x;
                    data.erase(fi);
                    data.insert(z);
                }
            }

        }
        else
        {
            scanf("%d%d",&x[0],&x[1]);
        }
    }
    return 0;
}
/*tmp.x=x[1]+1;
            fi=data.find(tmp);
            if(fi==data.end)
            {
                z.y=x[2];
                z.x=x[1]+1;
                data.insert(z);
            }
            else
            {
                z.y=x[2]+(*fi).y;//fi->y
                z.x=x[1]+1;
                data.erase(fi);
                data.insert(z);
            }*/
/*pair<set<tree>::iterator, bool> tmp;
tmp = data.insert(z);
tmp.first;
tmp.second;*/
