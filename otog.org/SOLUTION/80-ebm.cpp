#include <stdio.h>
#include <stdlib.h>
#include <set>
#define MAX(a,b) (a>b)?a:b
using namespace std;

int data[100050][3]={0};
int ans[100050]={0};
multiset<struct dt> work;
struct dt
{
    int val,idx;
    bool operator < (const dt &T) const
    {
        return val > T.val;
    }
    dt(int a,int b)
    {
        val=a;
        idx=b;
    }
};
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]<bb[1]) return 1;
    else return -1;
}
int main()
{
    int n;
    int mx=0,p,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&data[i][0],&data[i][1]);
        data[i][2]=i+1;
        mx=MAX(mx,data[i][0]);
    }
    qsort(data,n,sizeof(data[0]),cmp);
    p=0;
    for(int i=mx;i>=1;i--)
    {
        while(p<n&&data[p][0]>=i)
        {
            work.insert(dt(data[p][1],data[p][2]));
            p++;
        }
        if(!work.empty())
        {
            multiset<struct dt>::iterator pt;
            pt=work.begin();
            ans[cnt++]=pt->idx;
            work.erase(pt);
        }
    }
    printf("%d\n",cnt);
    for(int i=cnt-1;i>=0;i--) printf("%d\n",ans[i]);
    return 0;
}
