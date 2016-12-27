#include <stdio.h>

using namespace std;

int a[1005]= {0},b[1005]= {0};
int main()
{
    int T,x;
    scanf("%d",&T);
    while(--T>=0)
    {
        int n,m,w;
        scanf("%d%d",&n,&w);
        a[0]=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&m);
            for(int k=0;k<m;k++)
            {
                scanf("%d",&x);
                for(int j=0; j<=w; j++)
                {
                    if(a[j]==1&&j+x<=w) {b[j+x]=1;}
                }
            }
            for(int j=0; j<=w; j++) {a[j]=b[j];b[j]=0;}
        }

        for(int j=w; j>=0; j--)
        {
            if(j==0) printf("-1\n");
            if(a[j]==1) {printf("%d\n",j);break;}
        }
        for(int j=0; j<=w; j++) a[j]=b[j]=0;
    }

    return 0;
}
