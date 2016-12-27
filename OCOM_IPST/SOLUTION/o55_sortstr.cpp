#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    string x;
    vector<string> S;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        S.push_back(x);
    }
    sort(S.begin(),S.end());
    for(int i=0;i<n;i++) cout << S[i] << endl;
    return 0;
}
