#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int main()
{
    int tmp,i;
    set<int> arr;
    set<int>::iterator pt;
    for(i=0;i<5;i++)
    {
        scanf("%d",&tmp);
        arr.insert(tmp);
        pt=arr.begin();
        while(pt!=arr.end())
        {
            printf("%d ",*pt);
            pt++;
        }
        printf("\n");
    }
    return 0;
}
