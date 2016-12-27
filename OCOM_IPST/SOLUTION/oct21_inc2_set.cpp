#include <stdio.h>
#include <utility> //pair
#include <set>
using namespace std;

set<int> st;
pair<set<int>::iterator ,bool > p;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        p=st.insert(a);
        if(p.second==false) continue;
        p.first++;
        if(p.first!=st.end()) st.erase(p.first);
    }
    printf("%d",st.size());
    return 0;
}
