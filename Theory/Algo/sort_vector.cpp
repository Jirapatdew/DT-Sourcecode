#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(const int &a,const int &b){
    return a>b;
}

bool cmp_2D(const vector<int> &a,const vector<int> &b){
        return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);
}

struct cmp_class{
    bool operator ()(const int &a,const int &b){
        return a>b;
    }
}cmp_func;

struct cmp_class_2D{
    bool operator ()(const vector<int> &a,const vector<int> &b){
        return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);
    }
}cmp_func_2D;
int main()
{
    int n;
    vector<int> a;
    vector<vector<int> > b;
    //b[5].push_back(999);
    //cout << b[5][0];
    scanf("%d",&n);

//    a.resize(n);
//    for(int i=0;i<n;i++) scanf("%d",&a[i]);
//    sort(a.begin(),a.end(),cmp);
//    //sort(a.begin(),a.end(),cmp_func);
//    //sort(a.begin()+5,a.end());
//    for(int i=0;i<n;i++) printf("%d ",a[i]);

    b.resize(n);
    for(int i=0;i<n;i++) b[i].resize(2);
    for(int i=0;i<n;i++) scanf("%d%d",&b[i][0],&b[i][1]);
    //sort(b.begin(),b.end(),cmp_func_2D);
    //sort(b.begin()+5,b.end(),cmp_func_2D);
    sort(b.begin(),b.end(),cmp_2D);
    //sort(b.begin()+5,b.end(),cmp_2D);
    for(int i=0;i<n;i++) printf("%d %d\n",b[i][0],b[i][1]);
    return 0;
}
//10
//7 8 -5 4 5 7 15 9 51 11

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
