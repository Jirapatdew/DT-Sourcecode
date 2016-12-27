#include <stdio.h>

using namespace std;

int ans[100]={0},cnt=0;;
int main()
{
    int n;
    int l=1,sum=0,num=0;
    scanf("%d",&n);
    while(sum+l*2<n) {l*=2;sum+=l;num++;}
    n=n-sum-1;
    while(n>0)
    {
        ans[cnt++]=(n&1);
        n/=2;
    }
    for(int i=num;i>=0;i--)
    {
        if(ans[i]==0) printf("4");
        else printf("7");
    }
    return 0;
}
