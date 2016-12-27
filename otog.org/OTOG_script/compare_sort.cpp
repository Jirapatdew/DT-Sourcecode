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
    /////////// COPY DATA FROM FILE TO VARIABLE AND DELETE IGNORE SYMBOL///////////////////
    while( !fsol.eof() )
    {
        int i;
        getline(fsol, line, '\n');
        for( i=line.length()-1; i>=0 && iswhitespace(line[i]) ; --i );
        if( i>=0 )
            line = line.substr(0, i+1);
        if( line[0]!='\0' )
            data_sol.push_back( line );
    }
    while( !fout.eof() )
    {
        int i;
        getline(fout, line, '\n');
        for( i=line.length()-1; i>=0 && iswhitespace(line[i]) ; --i );
        if( i>=0 )
            line = line.substr(0, i+1);
        if( line[0]!='\0' )
            data_out.push_back( line );
    }
    fsol.close();
    fout.close();
    //////////////////////////////////////////////////////////////////////
    if( data_sol.size()!=data_out.size() ) {wrong();return 0;}

    //if(data_sol[0].compare(data_out[0])!=0) {wrong();return 0;}//CHECK FIRST LINE IS SAME
    sort(data_sol.begin(), data_sol.end());
    sort(data_out.begin(), data_out.end());
    int point=0;
    for(int i=0 ; i<data_sol.size() ; ++i )
    {
        if(data_sol[i].compare(data_out[i])==0) ++point;
    }
    if(point==data_sol.size()) {correct();return 0;}
    wrong();
	return 0;
}
