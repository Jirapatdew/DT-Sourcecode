#include <stdio.h>
using namespace std;

int st[1050]={0},cnt=1;
int in[1050]={0};
int p[1050]={0};

int print(int a)
{
    if(a<0) return 0;
    print(p[a]);
    printf("%d ",in[a]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    st[0]=-1;
    for(int i=1;i<=n;i++)
    {
        int lo=1,hi=cnt;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(in[st[mid]]<in[i]) lo=mid+1;
            else hi=mid;
        }
        if(lo==cnt)
        {
            st[cnt]=i;
            p[i]=st[cnt-1];
            cnt++;
        }
        else
        {
            p[i]=st[lo-1];
            st[lo]=i;
        }
    }
    printf("%d\n",cnt-1);
    print(st[cnt-1]);
    return 0;
}
