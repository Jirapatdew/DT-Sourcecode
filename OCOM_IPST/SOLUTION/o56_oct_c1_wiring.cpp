#include <stdio.h>
#include <stdlib.h>
using namespace std;

int chk1[100010]={0};
int chk2[100010]={0};
int idx[100010]={0};
int idx2[100010]={0};
int in[100010]={0};
int main()
{
    int T;
    int n,a,ans;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%d",&n);
        ans=1;
        for(int i=0;i<=n;i++) {chk1[i]=chk2[i]=idx[i]=idx2[i]=in[i]=0;}
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            in[i]=a;
            if(a!=0) idx[a]=i;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a!=0) idx2[a]=i;
            if(a==0) continue;
            if(i==idx[a]){chk1[i]=chk2[i]=1;continue;}
            if(chk2[i]==0||chk1[idx[a]]==0||idx[a]>i)
            {
                chk1[i]=1;
                chk2[idx[a]]=1;
            }
            else if(idx2[in[i]]<idx[a])
            {
                chk1[i]=1;
                chk2[idx[a]]=1;
            }
            else ans=0;
        }
        if(ans==0) printf("NO\n");
        else printf("YES\n");
        T--;
    }
    return 0;
}
