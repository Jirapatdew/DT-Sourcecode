#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(const string &a,const string &b){
    return a.compare(b)>0;//greater than
}

int qcmp(const void *a,const void *b){
    return strcmp((char*)b,(char*)a);
}
int main()
{
    int n;
    string s[100];
    char c[100][100];
    cin >> n;

//    for(int i=0;i<n;i++) cin>>s[i];
//    //sort(s,s+n);
//    sort(s,s+n,cmp);
//    for(int i=0;i<n;i++) cout<<s[i]<<endl;
    for(int i=0;i<n;i++) scanf("%s",c[i]);
    qsort(c,n,sizeof(c[0]),qcmp);
    for(int i=0;i<n;i++) printf("%s\n",c[i]);
    return 0;
}

//10
//gfjdgl
//aihalg
//kceqw
//kfhoi
//sdaf
//s
//gfg
//kfhcsafdghg
//ooierbhghg
//ooier
