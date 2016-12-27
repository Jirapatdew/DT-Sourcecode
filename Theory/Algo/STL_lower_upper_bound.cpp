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
    dt() : s(),x(),y(){}
    dt(string _s, int _x, int _y) : s(_s),x(_x),y(_y){}
    bool operator < (const dt &T) const{
        int scmp = s.compare(T.s);
        if(scmp<0) return true;
        else if(scmp==0&&((x<T.x)||(x==T.x&&y<T.y))) return true;
        else return false;
    }
    void print(){
        cout << s << " ";
        printf("%d %d\n",x,y);
    }
};
bool cmp (const dt &a,const dt &b){
    int scmp = a.s.compare(b.s);
    if(scmp<0) return true;
    else if(scmp==0&&a.x<b.x) return true;
    else return false;
}
int main()
{
    dt a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> a[i].s;
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a,a+n);
    printf("-----------------------------\n");
    for(int i=0;i<n;i++) a[i].print();

    printf("-----------------------------\n");

    dt *pt_lo,*pt_up;
    pt_lo = lower_bound(a,a+n,dt("a",4,0),cmp);
    pt_up = upper_bound(a,a+n,dt("a",4,0),cmp);
    printf("ans = %d\n",pt_up-pt_lo);

    printf("-----------------------------\n");

    pt_lo = lower_bound(a,a+n,dt("a",4,2));
    pt_up = upper_bound(a,a+n,dt("a",4,2));
    printf("ans2 = %d\n",pt_up-pt_lo);

    printf("-----------------------------\n");


    dt xx=dt("a",4,0);
    dt yy=xx;
    xx.print();
    yy.print();
    xx.s="fdsf";
    xx.y=99;
    xx.print();
    yy.print();
    return 0;
}
//12
//aaaa 1 8
//a 4 8
//fsd 87 54
//aaa 8 8
//a 4 2
//sda 1 56
//age 8 45
//fss 87 1
//a 4 2
//aaaa 8 1
//a 2 3
//a 1 1
