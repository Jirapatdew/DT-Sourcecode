#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>

#define INF 1000000000
#define MAX(_x,_y) ((_x>_y)?_x:_y)
#define MIN(_x,_y) ((_x>_y)?_y:_x)
#define NL printf("\n")

using namespace std;

long long qsum[1000100]={};

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&qsum[i]);
		qsum[i]+=qsum[i-1];
	}
	int x,y;
	for(int i = 0; i < q; i++)
	{
		scanf("%d %d",&x,&y);
		printf("%lld\n",qsum[y]-qsum[x-1]);
	}
	return 0;
}