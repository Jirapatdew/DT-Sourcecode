#include <iostream>

using namespace std;

int main()
{
    int n,mx,mn,a;
    cin >> n >> a;
    mx = mn =a;
    for(int i=1;i<n;i++){
        cin >> a;
        if(a>mx) mx = a;
        if(a<mn) mn = a;
    }
    cout << mn << endl << mx;
    return 0;
}
