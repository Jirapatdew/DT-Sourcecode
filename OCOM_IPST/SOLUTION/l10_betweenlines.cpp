#include <stdio.h>

using namespace std;

int a[10010]={0};
int main()
{
    int n;
    int w=1,u=1,m=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++) if(a[i]==13&&a[i+1]==10) {i++;w++;}
    for(int i=0;i<n;i++) {if(a[i]==10) u++; if(a[i]==13) m++;}
    printf("%d %d %d",w,u,m);
    return 0;
}
