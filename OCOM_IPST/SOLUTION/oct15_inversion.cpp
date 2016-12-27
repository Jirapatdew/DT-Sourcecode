#include <stdio.h>

using namespace std;

int a[100010]={0};
int b[100010]={0};
long long num=0;
int merge(int L,int M,int R)
{
    int i=L,j=M+1;
    for(int k=L;k<=R;k++)
    {
        if(i>M) {b[k]=a[j++];continue;}
        if(j>R) {b[k]=a[i++];continue;}
        if(a[i]>a[j])
        {
            b[k]=a[j++];
            num+=M+1-i;
        }
        else b[k]=a[i++];
    }
    for(int k=L;k<=R;k++) a[k]=b[k];
}
int mergesort(int L,int R)
{
    int M=(L+R)/2;
    if(L>=R) return 0;
    mergesort(L,M);
    mergesort(M+1,R);
    merge(L,M,R);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergesort(0,n-1);
    printf("%lld",num);
    return 0;
}
