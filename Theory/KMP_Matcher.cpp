#include <stdio.h>
#include <string.h>

using namespace std;

//T[1..n] P[1..m]
int pi[1000010]={0};
int Compute_Prefix_Fn(char P[])
{
    int m=strlen(P+1);
    pi[1]=0;
    int k=0;
    for(int q=2;q<=m;q++)
    {
        while(k>0 and P[k+1]!=P[q]) k=pi[k];
        if(P[k+1]==P[q]) k++;
        pi[q]=k;
    }
}
int KMP(char T[],char P[])
{
    int ans=0;
    int n=strlen(T+1);
    int m=strlen(P+1);
    Compute_Prefix_Fn(P);
    int q=0;
    for(int i=1;i<=n;i++)
    {
        while(q>0 and P[q+1]!=T[i]) q=pi[q];
        if(P[q+1]==T[i]) q++;
        if(q==m)
        {
            //printf("%d\n",i-m);
            ans++;
            q=pi[q];
        }
    }
    return ans;
}
int main()
{
    char T[1000020],P[1000020];
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s%s",T+1,P+1);
    printf("%d",KMP(T,P));
    return 0;
}
