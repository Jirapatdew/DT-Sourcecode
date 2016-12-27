#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

int a[100050]={0};
int b[100050]={0};
int cmp(const void*a,const void *b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    qsort(a,n,sizeof(int),cmp);
    qsort(b,m,sizeof(int),cmp);
    if(a[0]>b[0]) {printf("YES");return 0;}
    int i=0;
    for(int j=0;j<m;j++)
    {
        if(i==n) {printf("NO");return 0;}
        if(b[j]>=a[i]) i++;
        else {printf("YES");return 0;}
    }
    if(i<n) {printf("YES");return 0;}
    printf("NO");
    return 0;
}