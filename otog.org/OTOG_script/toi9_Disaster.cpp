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
	vector<string>	pathvec;
	string			path;
	string			line;
	int				n;

	ifstream fsol, fout;
	result.open("grader_result.txt");
	fsol.open(argv[1]); //OPEN SOLUTION FILE
	//fsol.open("1.sol");
	fout.open("output.txt"); //OPEN USER'S SOLUTION FILE
	if( !fout || !fsol  ) {wrong();return 0;}


    fsol >> n;
    for (int p=0; p<n; p++)
	{
		fsol >> path;
		pathvec.push_back(path);
	}
	getline(fout, line, '\n');
	path=line.c_str()[0];
    fsol.close();
    fout.close();
	for (int i=2; i<line.size(); i+=2)
	{
		path += line.c_str()[i];
		vector<string>::iterator it;
		bool found = false;
		for (int c=0; c<2; c++)
		{
			it = find(pathvec.begin(), pathvec.end(), path);
			if ( it != pathvec.end())
			{
				pathvec.erase(it);
				path = line.c_str()[i];
				found = true;
				break;
			}
			else {
				string temp(path.rbegin(), path.rend());
				path = temp;}
		}
		if (!found) break;
	}
	if(pathvec.size() > 0) wrong();
	else correct();
	return 0;
}
