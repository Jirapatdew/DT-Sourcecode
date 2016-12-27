#include <cstdio>
#include <algorithm>
using namespace std;

int pk[1000100]={};

int main()
{
	int n,q,a,b,len;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pk[i]);
	}
	sort(pk,pk+n);
	while(q--)
	{
		scanf("%d %d",&a,&b);
		len = upper_bound(pk,pk+n,b)-lower_bound(pk,pk+n,a);
		printf("%d\n",len);
	}
	return 0;
}
