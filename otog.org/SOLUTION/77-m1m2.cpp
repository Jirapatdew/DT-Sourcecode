#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int A[100500]={0};
int B[100500]={0};
int l[100500]={0};
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,m,a,b,t_A,t_B;
    double mn=2000000500;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    for(int i=0;i<m;i++) scanf("%d",&B[i]);
    for(int i=0;i<m;i++) scanf("%d",&l[i]);
    qsort(A,n,sizeof(int),cmp);
    for(int i=0;i<m;i++)
    {
        long long ai=((long long)B[i]*a)/b;
        int *p,x,y;
        double num;
        p=lower_bound(A,A+n,ai);
        x=b-a;
        for(int k=p-A;k>=p-A-1&&k>=0;k--)
        {
            y=B[i]-A[k];
            num=sqrt((long long)a*a+(long long)A[k]*A[k])+sqrt((long long)x*x+(long long)y*y)+l[i];
            if(num<mn)
            {
                t_A=k;
                t_B=i;
                mn=num;
            }
        }
    }
    //printf("%d %d\n",t_A,t_B);
    printf("%.4lf",mn);
    return 0;
}
