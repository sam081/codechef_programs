#include <stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int m,n,o;
	while(test--)
	{
		scanf("%d",&m);
		scanf("%d",&n);
		scanf("%d",&o);
		int sum=0;
		sum=4*(m+n+o-6);
		printf("%d\n",sum);
	}
}
