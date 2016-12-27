#include <cstdio>

using namespace std;

int x[100005]={0};
int y[100005]={0};
int data[100005][2];
int main()
{
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&data[i][0],&data[i][1]);
        x[data[i][0]]++;
        y[data[i][1]]++;
    }
    for(int i=0;i<n;i++) sum+=(long long)(x[data[i][0]]-1)*(long long)(y[data[i][1]]-1);
    printf("%lld",sum);
    return 0;
}
