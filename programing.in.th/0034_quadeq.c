#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,x,i,j,pass=0;
    int a,b,c,d;
    int minus=0;//-C?
    int pa=0,pc=0;
    int factor_A[201]={0};
    int factor_C[201]={0};
    scanf("%d%d%d",&A,&B,&C);
    if(C<0) {x=C*-1;}
    else x=C;
    for(i=1;i<=A;i++) if(A%i==0) factor_A[pa++]=i;
    for(i=-x;i<=x;i++) if(i!=0&&C%i==0) factor_C[pc++]=i;
    for(i=0;i<pa;i++)
    {
        a=factor_A[i];
        c=A/factor_A[i];
        for(j=0;j<pc;j++)
        {
            b=factor_C[j];
            d=C/factor_C[j];
            if(B==(a*d)+(b*c)) {pass=1;break;}
        }
        if(pass==1) break;
    }
    if(pass==1) printf("%d %d %d %d",a,b,c,d);
    else printf("No Solution");
    return 0;
}
