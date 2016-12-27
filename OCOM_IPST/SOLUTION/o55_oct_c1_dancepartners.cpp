#include <stdio.h>
#include <set>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
using namespace std;

int A[100010]={0};
int H[100010]={0};
int B[100010]={0};
int K[100010]={0};
struct cmpclass
{
    bool operator ()(const int& a,const int& b) const
    {
        return a>b;
    }
};
multiset<int,cmpclass> Hi;
multiset<int,cmpclass> Lo;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&H[i],&A[i]);
    for(int i=0;i<n;i++) scanf("%d%d",&K[i],&B[i]);
    for(int i=0;i<n;i++) Hi.insert(B[i]-K[i]);
    int j=0;
    for(int i=0;i<n;i++)
    {
        int mx=0;
        while(K[j]<H[i]&&j<n)
        {
            Hi.erase(Hi.find(B[j]-K[j]));
            Lo.insert(B[j]+K[j]);
            j++;
        }
        if(!Hi.empty()) mx=A[i]+H[i]+(*Hi.begin());
        if(!Lo.empty()) mx=MAX(mx,A[i]-H[i]+(*Lo.begin()));
        printf("%d\n",mx);
    }
    return 0;
}
