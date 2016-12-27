#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,i,j,k;
    int x[105]={0},y[105]={0};
    double max,a;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                a=abs(x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - y[i]*x[j] - y[j]*x[k] - y[k]*x[i])/(double)2;
                if(a>max) max=a;
            }
        }
    }
    printf("%.3lf",max);
    return 0;
}
