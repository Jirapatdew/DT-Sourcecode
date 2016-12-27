#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

list<int> a;
list<int>::iterator it;
char data[100005][15];
int d=1;
void insert()
{
    scanf("%s",data[d]);
    a.insert(it,d);
    d++;
}
void left()
{
    if(it!=a.begin()) it--;
}
void right()
{
    if(it!=a.end()) it++;
}
void backspace()
{
    if(it!=a.begin())
    {
        it--;
        it=a.erase(it);
    }
}
void del()
{
    if(it!=a.end()) it=a.erase(it);
}
int main()
{
    int n,i;
    char x;
    scanf("%d",&n);
    it=a.begin();
    for(i=1; i<=n; i++)
    {
        scanf(" %c",&x);
        if(x=='i') insert();
        else if(x=='l') left();
        else if(x=='r') right();
        else if(x=='b') backspace();
        else if(x=='d') del();
    }
    it=a.begin();
    while(it!=a.end())
    {
        printf("%s ",data[*it]);
        it++;
    }

    return 0;
}
