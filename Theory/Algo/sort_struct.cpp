#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

struct dt{
    string s;
    int x;
    int y;
    bool operator < (const dt &T) const{
        int scmp = s.compare(T.s);
        if(scmp<0) return true;
        else if(scmp==0&&((x<T.x)||(x==T.x&&y<T.y))) return true;
        else return false;
    }
};
bool cmp(const dt &a,const dt &b){
    return a.x<b.x;
}
struct cmp_class{
    bool operator ()(const dt &a,const dt &b){
        return a.y<b.y;
    }
}cmp_func;

int main()
{
    dt a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> a[i].s;
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    //sort(a,a+n);
    //sort(a,a+n,cmp);
    sort(a,a+n,cmp_func);
    for(int i=0;i<n;i++){
        cout << a[i].s << " ";
        printf("%d %d\n",a[i].x,a[i].y);
    }
    return 0;
}

//10
//aaaa 1 8
//a 4 8
//fsd 87 54
//aaa 8 8
//a 5 6
//sda 1 56
//age 8 45
//fss 87 1
//a 4 2
//aaaa 8 1


