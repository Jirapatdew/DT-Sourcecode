#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>

#define SQR(_x) ((_x)*(_x))
#define REP(_i,_n) for(int _i = 0; _i < (int)(_n); _i++)
#define FOR(_i,_a,_b) for(int _i = (int)(_a); _i <= (int)(_b); _i++)
#define BCK(_i,_a,_b) for(int _i = (int)(_a); _i >= (int)(_b); _i--)
#define NL printf("\n")
#define LL long long
#define INF 1000000000

using namespace std;

vector<int> v[200];

int clr[200]={};

bool color(int k,int c)
{
	int size = v[k].size();
	REP(i,size)
	{
		if(clr[v[k][i]]==0)
		{
			clr[v[k][i]]=!c+1;
			if(color(v[k][i],!c)==false)
				return false;
		}
		else if(clr[v[k][i]]==c+1)
			return false;
	}
	return true;
}

int main()
{
	int n,x;
	scanf("%d",&n);
	FOR(i,1,n)
	{
		while(true)
		{
			scanf("%d",&x);
			if(x==0)
				break;
			v[i].push_back(x);
			v[x].push_back(i);
		}
	}
	FOR(i,1,n)
	{
		if(clr[i]==0)
		{
			clr[i]=1;
			if(color(i,0)==false)
			{
				printf("no");
				return 0;
			}
		}
	}
	printf("yes");
	return 0;
}
