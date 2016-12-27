#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
using namespace std;

int main()
{
    int a[50010]={0},mx=0,total=0;
    int top=1,num[50010]={0};
    int n;
    char ch;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&ch);
        if(ch=='(') a[top++]=1;
        else
        {
            top--;
            mx=MAX(mx,a[top]);
            total++;
            num[a[top]]++;
            a[top-1]=MAX(a[top-1],a[top]+1);
            a[top]=0;
        }
    }
    printf("%d\n",total);
    printf("%d\n",mx);
    for(int i=1;i<=mx;i++) printf("%d ",num[i]);
    return 0;
}

///((())(()((()))))
