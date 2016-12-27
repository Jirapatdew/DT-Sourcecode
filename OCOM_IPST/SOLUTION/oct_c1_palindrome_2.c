#include <stdio.h>
#include <stdlib.h>

// l(i,j)=longest palindromic subsequence from i to j;
//find l(1,n);

//l(i,j) = l(i+1,j-1)+2             if a[i]==a[j] && i!=j
//       = max(l(i+1,j),l(i,j-1))   if a[i]!=a[j]
//       = 1                        if i==j
int l[5005][5005]={0};
int a[5005]={0};
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=n;i>0;i--)
    {
        for(j=i;j<=n;j++)
        {
            if(a[i]==a[j] && i!=j) l[i][j]=l[i+1][j-1]+2;
            else if(i==j) l[i][j]=1;
            else if(a[i]!=a[j]) l[i][j]=max(l[i+1][j],l[i][j-1]);
        }
    }
    printf("%d",l[1][n]);
}
