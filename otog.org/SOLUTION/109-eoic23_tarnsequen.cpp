#include <stdio.h>
using namespace std;

int st[100050]={0},cnt=1;
int in[100050]={0};
int p[100050]={0};

int print(int a)
{
    if(a<0) return 0;
    printf("%d ",in[a]);
    print(p[a]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    st[0]=-1;
    for(int i=n;i>=1;i--)
    {
        int lo=1,hi=cnt;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(in[st[mid]]>in[i]) lo=mid+1;
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
            //if(in[st[lo]]==in[i])
            p[i]=st[lo-1];
            //else p[i]=p[st[lo]];
            st[lo]=i;
        }
    }
    printf("%d\n",cnt-1);
    print(st[cnt-1]);
    return 0;
}
