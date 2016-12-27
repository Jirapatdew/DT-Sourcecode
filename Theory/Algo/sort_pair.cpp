#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return (a.first>b.first)||((a.first==b.first)&(a.second>b.second));
}// True -> a<b , False -> b<a sort less

struct cmp_class{
    bool operator () (const pair<int,int> &a,const pair<int,int> &b){
        return (a.first>b.first)||((a.first==b.first)&(a.second>b.second));
    }
}cmp_fuc;


int main()
{
    int n;
    int a[1005]={0};
    pair<int,int> b[1005];

    scanf("%d",&n);
//    for(int i=0;i<n;i++) scanf("%d",&a[i]);
//    sort(a,a+n);
//    for(int i=0;i<n;i++) printf("%d ",a[i]);
//    printf("\n");

//    for(int i=0;i<n;i++) scanf("%d%d",&b[i].first,&b[i].second);
//    sort(b,b+n);
//    for(int i=0;i<n;i++) printf("%d %d\n",b[i].first,b[i].second);
//    printf("\n");


    for(int i=0;i<n;i++) scanf("%d%d",&b[i].first,&b[i].second);
    sort(b,b+n,cmp_fuc);//sort(b,b+n,cmp);
    for(int i=0;i<n;i++) printf("%d %d\n",b[i].first,b[i].second);
    printf("\n");


    return 0;
}

//10
//1 7
//2 4
//9 3
//9 2
//4 8
//4 1
//7 8
//1 1
//4 2
//4 9
