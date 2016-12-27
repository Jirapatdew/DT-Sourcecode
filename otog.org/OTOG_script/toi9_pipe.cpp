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
vector< string > data_sol;
vector< string > data_out;
string line;

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
	fsol.open(argv[1]); //OPEN SOLUTION FILE
	//fsol.open("1.sol");
	fout.open("output.txt"); //OPEN USER'S SOLUTION FILE


	if( !fout || !fsol  ) {wrong();return 0;}

	int psol, pout;

	fsol >> psol;
	fout >> pout;
    if(psol!=pout) {wrong();return 0;}
    vector<int> sollen;
    vector<int> outlen;

    for(int i=0; i<psol; i++) {
        int x;
        fsol >> x;
        sollen.push_back(x);

        fout >> x;
        outlen.push_back(x);
    }
    fsol.close();
    fout.close();
    sort(sollen.begin(),sollen.end());
    sort(outlen.begin(),outlen.end());
    for(int i=0; i<psol; i++)
    {
        if(sollen[i]!=outlen[i]) {wrong();return 0;}
    }
    correct();
    return 0;
}
