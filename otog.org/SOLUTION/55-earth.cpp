#include <stdio.h>
#include <stdlib.h>
using namespace std;
int data[100050]={0},up[100050]={0},down[100050]={0};
int main()
{
    int n,m;
    int l,r;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    for(int i=2;i<=n;i++) //build down
        if(data[i]<=data[i-1]) down[i]=down[i-1]+1;
        else down[i]=0;
    for(int i=n-1;i>0;i--) //build up
        if(data[i]<=data[i+1]) up[i]=up[i+1]+1;
        else up[i]=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        if(up[l]+down[r]>=r-l-1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
