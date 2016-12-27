#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[15]={0},B[15]={0},C[15]={0},D[15]={0};
    int pa=9,pb=9,pc=9,pd=9;
    int n,i,j,a,b,t;
    long long total=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n/2;j++)
        {
            scanf("%d%d",&a,&b);
            if(i%2==0) {A[a]++;B[b]++;}
            else {C[a]++;D[b]++;}
        }
    }
    t=n*n/4;
    for(i=0;i<t;i++)
    {
        while(A[pa]==0) pa--;
        while(B[pb]==0) pb--;
        while(C[pc]==0) pc--;
        while(D[pd]==0) pd--;
        total+=pa*pb*pc*pd;
        A[pa]--;B[pb]--;C[pc]--;D[pd]--;
    }
    printf("%lld",total);
    return 0;
}
