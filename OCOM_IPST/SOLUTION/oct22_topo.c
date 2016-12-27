#include <stdio.h>
#include <stdlib.h>

int notdag=0,topo=0,ans[100001];//ans=�ӵͺ���໧Topological Sort(�纨ҡ��ѧ�˹��)
int G[100001]={0},p[101]={0},s[100001]={0},x[100001];
    //G=�������ѧ������������á chi=��������  p=���  s=ʶҹ�(  0=�բ�� 1=����  2=�մ� )  x=��Ǫ��͡�ѹ�Ѻ��͹˹��
int chi[200001][2]={0};
int dfs(int u)//u=��������
{
    int i,k;
    s[u]=1;
    if(G[u]!=0)k=G[u];
    else k=-1;
    while(k!=-1)
    {
        if(s[chi[k][0]]==0)
        {
            dfs(chi[k][0]);
        }
        else if(s[chi[k][0]]==1) {notdag=1;}
        k=chi[k][1];
    }
    ans[topo++]=u;
    s[u]=2;
}
int main()
{
    int i,n,m,a;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        scanf("%d",&chi[i][0]);
        if(G[a]==0) G[a]=i;
        else chi[x[a]][1]=i;
        chi[i][1]=-1;
        x[a]=i;
    }
    for(i=1;i<=n;i++)
    {
        if(G[i]!=0)
        {
            if(s[i]==0) dfs(i);
            if(notdag==1) break;
        }
    }
    if(notdag==1) printf("no");
    else for(i=topo-1;i>=0;i--) printf("%d\n",ans[i]);
    return 0;
}
