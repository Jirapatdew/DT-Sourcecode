//stable matching theory
#include <stdio.h>
#include <vector>
using namespace std;

int pt[110]={0};//address
int a[110][110]={0};//S_like
int b[110][110]={0};//day
int P[110][110]={0};//P_like
int ck[110]={0};
vector<int> v;
int reset()
{
    for(int i=0;i<110;i++)
    {
        //for(int j=0;j<110;j++) {a[i][j]=0;b[i][j]=0;}
        pt[i]=1;
        ck[i]=0;
    }
}
int main()
{
    int T;
    int n,m,x;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&m);
        reset();
        for(int i=1;i<=n;i++)
        {
            int num=1;
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&x);
                if(x==0) continue;
                a[i][num]=x;
                b[i][num]=j;
                P[x][i]=j;
                num++;
            }
        }
        for(int i=n;i>=1;i--) v.push_back(i);
        while(!v.empty())
        {
            x=v.back();
            v.pop_back();
            while(pt[x]<=n)
            {
                int u=a[x][pt[x]];
                if(ck[u]==0) {ck[u]=x;break;}
                else if(P[u][x]>P[u][ck[u]])
                {
                    pt[ck[u]]++;
                    v.push_back(ck[u]);
                    ck[u]=x;
                    break;
                }
                pt[x]++;
            }
        }
        printf("TEST %d\n",t);
        for(int i=1;i<=n;i++) printf("%d\n",b[i][pt[i]]);
    }

    return 0;
}
