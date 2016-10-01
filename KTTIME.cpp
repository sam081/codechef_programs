#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,counter=0;
		scanf("%d",&n);
		long long int a[100000],b[100000],c[100000];

		for(int i=0;i<n;i++)    //moments at which a slots completes
			scanf("%lld",&a[i]);

		for(int i=0;i<n;i++)
			scanf("%lld",&b[i]);
		for(int i=0;i<n;i++)
		{
		    int temp;
		    if(i==0)
                temp=a[0];
            else
                temp=a[i]-a[i-1];
			if(b[i] <= temp)
				counter++;
		}
		printf("%d\n",counter);
	}
	return 0;
}
