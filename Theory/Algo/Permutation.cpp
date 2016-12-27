#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int x[100]={0};
int perm(int m){
    if(n==m){
        for(int i=1;i<=n;i++) printf("%d ",x[i]);
        printf("\n");
        return 0;
    }
    for(int i=m+1;i<=n;i++){
        swap(x[i],x[m+1]);
        perm(m+1);
        swap(x[i],x[m+1]);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) x[i]=i;
    perm(0);
    return 0;
}
