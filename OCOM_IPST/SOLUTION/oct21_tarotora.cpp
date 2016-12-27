#include <stdio.h>
#include <set>
#define INF 2000000000
#define MIN(a,b) ((a<b)?a:b)
using namespace std;

multiset<int> ST;
multiset<int>::iterator pt;
int ab(int a)
{
    if(a<0) return -a;
    else return a;
}
int main()
{
    int c;
    scanf("%d",&c);
    while(c>0)
    {
        int n,k,mn=INF,sum=0,n_a,n_b,a,b;
        scanf("%d%d",&n,&k);
        ST.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            sum+=a;
            ST.insert(b-a);
        }
        n_a=n;
        n_b=0;
        if(ab(n_a-n_b)<=k) mn=sum;
        pt=ST.begin();
        while(n_a>0)
        {
            sum+=*pt;
            n_a--;
            n_b++;
            if(ab(n_a-n_b)<=k) mn=MIN(mn,sum);
            pt++;
        }
        c--;
        printf("%d\n",mn);
    }
    return 0;
}
