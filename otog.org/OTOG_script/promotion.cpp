#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>

#define iswhitespace(x) ((x)==' '||(x)=='\t'||(x)=='\r')

using namespace std;
map<vector<int>,int> MAP;

ofstream result;
void correct(){
	result << 'P';
	result.close();
	exit(0);
}
void wrong(){
	result << 'W';
	result.close();
	exit(0);
}
int main(int argc, char * argv[])
{
	ifstream fsol, fout;
	result.open("grader_result.txt");
	//fsol.open(argv[1]); //OPEN SOLUTION FILE
	fsol.open("1.sol");
	fout.open("output.txt"); //OPEN USER'S SOLUTION FILE


	if( !fout || !fsol  ) {wrong();return 0;}

    int n,m,a;
    fsol >> n;
    for(int i=0;i<n;i++)
    {
        fsol >> m;
        vector<int> V;
        V.clear();
        for(int j=0;j<m;j++)
        {
            fsol >> a;
            V.push_back(a);
        }
        MAP[V]=1;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        fout >> m;
        vector<int> V;
        V.clear();
        for(int j=0;j<m;j++)
        {
            fout >> a;
            V.push_back(a);
        }
        sort(V.begin(),V.end());
        if(MAP.find(V)==MAP.end()) wrong();
        else cnt++;
    }
    fsol.close();
    fout.close();
    if(cnt==n) correct();
    wrong();
	return 0;
}
