#include <stdio.h>

using namespace std;

int N[100010]={0},sz=1;
int L[100010]={0},pt=1,pr=0,pl=0;//2= |>  1=<|
int R[100010]={0};
int main()
{
    int l,n;
    scanf("%d%d",&l,&n);
    for(int i=1;i<=l;i++)
    {
        int a;
        scanf("%d",&a);
        for(int j=sz+1;j<sz+a;j++) L[j]=j-1;
        for(int j=sz+a-2;j>=sz;j--) R[j]=j+1;
        sz+=a;
    }
    pt=1;
    pl=L[pt];
    pr=R[pt];
    char ch[5];
    int x,tmp;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='F')
        {
            if(pr!=0)
            {
                pl=pt;
                pt=pr;
                if(R[pr]!=pl) pr=R[pr];
                else pr=L[pr];
            }
            printf("%d\n",pt);
        }
        else if(ch[0]=='B')
        {
            if(pl!=0)
            {
                pr=pt;
                pt=pl;
                if(L[pl]!=pr) pl=L[pl];
                else pl=R[pl];
            }
            printf("%d\n",pt);
        }
        else
        {
            scanf("%d",&x);
            if(pr!=0)
            {
                if(L[pr]==pt) L[pr]=0;
                if(R[pr]==pt) R[pr]=0;
                if(L[pt]==pr) L[pt]=0;
                if(R[pt]==pr) R[pt]=0;
            }
            if(L[x]==0)
            {
                L[x]=pt;
                if(R[pt]==0) R[pt]=x;
                else L[pt]=x;
            }
            else
            {
                R[x]=pt;
                if(R[pt]==0) R[pt]=x;
                else L[pt]=x;
            }
            pr=x;
            if(pr!=0)
            {
                pl=pt;
                pt=pr;
                if(R[pr]!=pl) pr=R[pr];
                else pr=L[pr];
            }
            printf("%d\n",pt);
        }
    }


    return 0;
}
