#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
   /* map<string,int> a;
    string b;
    a["ta"]=20;
    cout << a["ta"];
    for(map<string,int>::iterator pt=a.begin();pt!=a.end();pt++)
        printf("%d",pt->second);*/
    //ex graph
    /*
    int connect[100][100]
    connect[3][4]=1;
    connect[4][3]=1;

    map<int,int> a[100];
    a[3][4]=10;
    for(map<int,int>::iterator pt=a[b].begin();pt!=a[b].end();pt++)
        printf("%d",pt->second);
    */
    ///build G
    int n,a,b,v;
    map<int,int> G[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&v);
        G[a][b]=v;
        G[b][a]=v;
    }
    return 0;
}
