#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<int,int> M;
map<int,int>::iterator it;
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    M[-1]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        M[a+1]+=1;
        M[b]-=1;
    }

    int c=0,sum=0;
    for(it=M.begin();it!=M.end();it++)
    {
        it->second+=c;
        c=it->second;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a);
        it=M.upper_bound(a);
        it--;
        sum+=it->second;
        sum%=2007;
    }
    cout << sum;
    return 0;
}
