#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> a;
    list<string>::iterator pt=a.begin(),it;
    string b;
    int n;
    char ch;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> ch;
        if(ch=='i')
        {
            cin >> b;
            a.insert(pt,b);
        }
        else if(ch=='l') {if(pt!=a.begin()) pt--;}
        else if(ch=='r') {if(pt!=a.end()) pt++;}
        else if(ch=='b') {if(pt!=a.begin()) pt=a.erase(--pt);}
        else if(ch=='d') {if(pt!=a.end()) pt=a.erase(pt);}
    }
    for(pt=a.begin();pt!=a.end();pt++) cout << *pt << " " ;
    return 0;
}
