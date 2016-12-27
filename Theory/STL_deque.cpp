#include <cstdio>
#include <deque>

using namespace std;

struct ST{
    int a,b;
};

int main(){
    deque <int> Q; // []
    Q.push_back(13); // [13]
    Q.push_back(12); // [13,12]
    Q.pop_front(); // [12]
    Q.push_front(11); // [11,12]
    Q.pop_back(); // [11]
    Q.push_back(5); // [11,5]
    printf("%d", Q.back()); // => 5
    printf("%d", Q.front()); // => 11
    for(int i = 0; i < 4; i++)
        Q.push_back(i);
    // [11,5,0,1,2,3]
    Q.push_front(-1); // [-1,11,5,0,1,2,3]
    for(int i = 0; i < Q.size(); i++)
        printf("%d ", Q[i]);
    // => -1 11 5 0 1 2 3
    while(!Q.empty())
        Q.pop_back();
    // []
    Q.pop_back(); // => Error
    Q.pop_front(); // => Error
    Q.front(); // => Error
    Q.back(); // => Error

    ST tmp;
    deque <ST> T; // []
    tmp.a = 5;
    tmp.b = 3;
    T.push_back(tmp); // [(5,3)]
    printf("%d\n", T.front().b); // => 3
    return 0;
}
