#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m[401][401],a[401][401],b[401][401],A,B,max=0;
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) scanf("%d",&m[i][j]);
    for(k=0;k<n;k++)
    {
        i=0;j=k;
        a[i][j]=m[i][j];
        while(j<n-1)
        {
            i++;j++;
            a[i][j]=m[i][j]+a[i-1][j-1];
        }
    }
    for(k=1;k<n;k++)
    {
        i=k;j=0;
        a[i][j]=m[i][j];
        while(i<n-1)
        {
            i++;j++;
            a[i][j]=m[i][j]+a[i-1][j-1];
        }
    }
    for(k=n-1;k>=0;k--)
    {
        i=0;j=k;
        b[i][j]=m[i][j];
        while(j>0)
        {
            i++;j--;
            b[i][j]=m[i][j]+b[i-1][j+1];
        }
    }
    for(k=1;k<n;k++)
    {
        i=k;j=n-1;
        b[i][j]=m[i][j];
        while(i<n-1)
        {
            i++;j--;
            b[i][j]=m[i][j]+b[i-1][j+1];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<=n-k;i++)
        {
            for(j=0;j<n-k;j++)
            {
                if(i>0&&j>0) A=a[i+k-1][j+k-1]-a[i-1][j-1];
                else A=a[i+k-1][j+k-1];
                if(i<n-1&&j<n-1) B=b[i+k-1][j]-b[i][j+k-1];
                else B=b[i+k-1][j]
                if(A-B>max) max=A-B;
            }
        }
    }
    printf("%d",max);
    return 0;
}
