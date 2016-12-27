#include <stdio.h>
#include <stdlib.h>

char d_A[105][35][5];
char d_B[105][35][5];
int c_A[105]={0};
int c_B[105]={0};
int truth[20]={0};
int t_A,t_B;
int n,m;
int p=0;
int max=0;
int find_A(int x,int c)
{
    int t,i;
    for(i=0;i<c;i++)
    {
        if(d_A[x][i][0]=='-')
        {
            if(truth[d_A[x][i][1]-'a']==0) t=1;
            else t=0;
        }
        else t=truth[d_A[x][i][1]-'a'];
        if(t==1) return 1;
    }
    return 0;
}
int find_B(int x,int c)
{
    int t,i;
    for(i=0;i<c;i++)
    {
        if(d_B[x][i][0]=='-')
        {
            if(truth[d_B[x][i][1]-'a']==0) t=1;
            else t=0;
        }
        else t=truth[d_B[x][i][1]-'a'];
        if(t==1) return 1;
    }
    return 0;
}
int bi(int a)
{
    int i,j;
    if(p==1) return 0;
    if(a>max)
    {
        for(j=0;j<n;j++)
        {
            if(find_A(j,c_A[j])) t_A=1;
            else {t_A=0; break;}
        }
        for(j=0;j<m;j++)
        {
            if(find_B(j,c_B[j])) t_B=1;
            else {t_B=0; break;}
        }
        if(t_A==1&&t_B==0) {printf("NO\n");p=1;}
        return 0;
    }
    for(i=0;i<2;i++)
    {
        truth[a]=i;
        bi(a+1);
    }
    return 0;
}
int main()
{
    int k;
    int i,j;
    scanf("%d",&k);
    for(;k>0;k--)
    {
        scanf("%d%d\n",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&c_A[i]);
            for(j=0;j<c_A[i];j++)
            {
                scanf("%s",d_A[i][j]);
                if(d_A[i][j][1]-'a'>max) max=d_A[i][j][1]-'a';
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&c_B[i]);
            for(j=0;j<c_B[i];j++)
            {
                scanf("%s",d_B[i][j]);
                if(d_B[i][j][1]-'a'>max) max=d_B[i][j][1]-'a';
            }
        }
        p=0;
        bi(0);
        if(p==0) printf("YES\n");
    }

    return 0;
}
