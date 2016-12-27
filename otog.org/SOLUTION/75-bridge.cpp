#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#define INF 		2000000000ll
#define FOR(i,a,b)	for(int i = a; i < b; i++)
#define MIN(a,b)	({a < b ? a : b;})
#define MAX(a,b)	({a > b ? a : b;})
#define AB(a)		({a < 0 ? -a : a;})
#define EQ(a,b)		({AB(a - b) <= 1e-10 ? true : false;})
#define CL(a)		memset(a,b,sizeof(a))
#define NOT(a)		a = not a

using namespace std;

int input[100];
int best[100] = {0};
int solve(int N){
	if(best[N] == 0){
		if(N == 1) return input[0];
		if(N == 2) return input[1];
		if(N == 3) return input[0] + input[1] + input[2];
		int a = input[N-1] + input[0] + solve(N-1);
		int b = input[1] + input[0] + input[N-1] + input[1] + solve(N-2);
		best[N] = MIN(a,b);
	}
	return best[N];
}
int main(){
	int N;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		scanf("%d", &input[i]);
	}
	sort(input, input+N);

	printf("%d\n", solve(N));
	return 0;
}