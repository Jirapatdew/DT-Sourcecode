#include <stdio.h>

using namespace std;

int T[1000010],NUM[1000010];
int n;
int freqTo(int FW[],int i)
{
    int sum=0;
    for(;i>0;i-=(i&-i)) sum+=FW[i];
    return sum;
}
void update(int FW[],int i,int val)
{
    for(;i<=n;i+=(i&-i)) FW[i]+=val;
}
int bi(int lo,int hi,int key)
{
    while(lo<hi)
    {
        int mid=(lo+hi)/2,x;
        x=freqTo(T,mid);
        if(x<key) lo=mid+1;
        else hi=mid;
    }
    return lo;
}
int main()
{
    int m,x,y,idx;
    char c[5];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) update(T,i,1);
//    for(int j=1;j<=n;j++) printf("%d ",freqTo(T,j));
//    printf("\n");
//    for(int j=1;j<=n;j++) printf("%d ",freqTo(NUM,j));
//    printf("\n");
    for(int i=1;i<=m;i++)
    {
        scanf("%s",c);
        if(c[0]=='d')
        {
            scanf("%d",&x);
            idx=bi(1,n,x+1);
            if(freqTo(NUM,idx)-freqTo(NUM,idx-1)==0&&freqTo(T,idx-1)==x)
            {
                update(NUM,idx,1);
                update(T,idx,-1);
            }
            else update(T,idx,-1);
        }
        else if(c[0]=='g')
        {
            scanf("%d",&x);
            idx=bi(1,n,x+1);
            update(T,idx,1);
        }
        else
        {
            int a,b,sum,tmp;
            scanf("%d%d",&a,&b);
            sum=freqTo(T,b-1)-freqTo(T,a-1)-1;
            tmp=freqTo(NUM,b-1)-freqTo(NUM,a);
            sum+=2*tmp-(b-a-1);
            printf("%d\n",sum);
        }
//        for(int j=1;j<=n;j++) printf("%d ",freqTo(T,j));
//        printf("\n");
//        for(int j=1;j<=n;j++) printf("%d ",freqTo(NUM,j));
//        printf("\n");
    }
    return 0;
}
