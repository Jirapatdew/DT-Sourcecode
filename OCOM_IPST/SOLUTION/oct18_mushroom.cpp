#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int main()
{
    multiset<int> map;
    multiset<int>::iterator pt;
    int n,l,h;
    int i,j,a,x,y,z;
    int tmp;
    scanf("%d%d%d",&n,&l,&h);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        for(j=0; j<a; j++)
        {
            scanf("%d",&tmp);
            map.insert(tmp);
        }
        scanf("%d%d",&x,&y);
        z=(h*x)/y;
        if((h*x)%y!=0&&x<0) z--;
        else if((h*x)%y!=0) z++;
        pt=map.lower_bound(z+l);////***
        map.erase(pt,map.end());
        printf("%d\n",(int)map.size());
    }
    return 0;
}
