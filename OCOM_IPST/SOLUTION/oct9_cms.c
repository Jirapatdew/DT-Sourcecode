#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int n;
    int i,a[50010]={0},p,s;//p=������Դ�ѹ�ҡ�ش����� i  s=������Դ�ѹ�ҡ�ش����� 1-i
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    p=s=a[0];
    for(i=1;i<n;i++)
    {
        p=max(p+a[i],a[i]);
        s=max(s,p);
    }
    printf("%d",s);
    return 0;
}
