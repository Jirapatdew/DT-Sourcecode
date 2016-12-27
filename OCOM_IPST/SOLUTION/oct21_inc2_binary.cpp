#include <stdio.h>
using namespace std;

int st[100050]={0},cnt=0;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        int lo=0,hi=cnt;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(st[mid]<a) lo=mid+1;
            else hi=mid;
        }
        if(lo==cnt) st[cnt++]=a;
        else st[lo]=a;
    }
    printf("%d",cnt);
    return 0;
}
