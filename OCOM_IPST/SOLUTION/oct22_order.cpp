#include <stdio.h>
#include <map>
using namespace std;

int pre[1050]={0};//idx 0-n
int idx[1050]={0};
map<int,int> post;


int bi(int L,int R,int num)
{
    if(L>R) return 0;
    int m=L++;
    int n_l=idx[L]-num+1;
    if(L-1==R)
    {
        printf("%d\n",pre[m]);
        return 0;
    }
    bi(L,L+n_l-1,num);
    printf("%d\n",pre[m]);
    bi(L+n_l,R,num+n_l);
}
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        post[x]=i;
    }
    for(int i=0;i<n;i++) idx[i]=post[pre[i]];
    bi(0,n-1,0);
    return 0;
}
