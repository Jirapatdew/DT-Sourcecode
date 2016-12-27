#include <iostream>
#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;

class interval {
public:
    long long sum;
    int idx;
    interval(long long sum=0,int idx=0):sum(sum),idx(idx){}
    bool operator >= (const interval &T) const {
        return (sum>T.sum)||(sum==T.sum&&idx>=T.idx);
    }
};

int ans_num=0;
long long ans_sum=0;
int main()
{
    int n,w,in;
    long long cal=0;
    deque<interval> DQ;

    scanf("%d%d",&n,&w);

    for(int i=0;i<n;i++){
        scanf("%d",&in);
        interval x(-cal,i);
        cal+=in;

        while(!DQ.empty() && DQ.front().idx<=i-w+1)
            DQ.pop_front();
        while(!DQ.empty() && x>=DQ.back())
            DQ.pop_back();
        DQ.push_back(x);

        //checkAns
        if(DQ.front().sum+cal>ans_sum){
            ans_sum = DQ.front().sum+cal;
            ans_num = i-DQ.front().idx+1;
        }
        else if(DQ.front().sum+cal==ans_sum) ans_num = min(ans_num,i-DQ.front().idx+1);
    }
    printf("%lld\n%d",ans_sum,ans_num);
    return 0;
}
