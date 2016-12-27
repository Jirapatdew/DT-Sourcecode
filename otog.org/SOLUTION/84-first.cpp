#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,x=2;
    int i,a;
    vector<int> data(700005);
    vector<int>::iterator pt;
    scanf("%d",&n);
    data[1]=1;
    data[2]=3;
    for(i=3;i<=674000;i++)
    {
        if(i>data[x]) x++;
        data[i]=data[i-1]+x;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        printf("%d\n",lower_bound(data.begin(),data.end()-26000,a)-data.begin());
    }
    return 0;
}
