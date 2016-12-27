#include <stdio.h>

using namespace std;

int f[2005]= {0};
int tmp[2005]= {0};
int main()
{
    int n,T;
    scanf("%d",&T);
    while(--T>=0)
    {
        for(int i=0;i<=2000;i++) f[i]=tmp[i]=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                if(f[j-i]!=0)
                {
                    tmp[j]=f[j-i]+f[j];
                }
            }
            tmp[i]++;
            for(int k=i; k<=n; k++) f[k]=tmp[k]%=1000003; //k=1
        }
        printf("%d\n",f[n]%=1000003);
    }
}
