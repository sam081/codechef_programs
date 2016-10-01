#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,c[100000],a[100000];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
        {
			scanf("%d",&c[i]);
		}
        int y=0;
		for(int i=0;i<n;i++)
        {
            if(c[i]==c[i+1] &&c[i+1]==c[i+2])
            {
                y=1;
                break;
            }
        }
        if(y==1)
            printf("Yes\n");
        else
            printf("No\n");
	}
}
