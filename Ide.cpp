//optimised algo
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d",&test);
	while(test--)
	{
	    int ans=0;
	    int n,a[100005];
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	        scanf("%d",&a[i]);
	    int temp1[100005]={0};//rank
	    int temp[100005]={0};//visited or not
	    int temp2[100005]={0};//stages
	    for(int i=0;i<n;i++)
	    {
	        if(temp[i]==0)//is_in[i]==0 && is_in1[i]==0)
	        {
	            int counter2=0;
    	        for(long long j=i; ; )
    	        {
    	            if(temp[j]==0)//is_in[j]==0 && is_in1[j]==0)
                    {
                        counter2++;
                        temp2[j]=i;
                        temp[j]=1;
                        temp1[j]=counter2;
                        j=(j+a[j]+1);
                        if(j>=n)
                            j=j%n;
                    }
                    else
                    {
                        if(temp2[j]==i)
                            ans=ans+counter2-temp1[j]+1;
                        break;
                    }
    	        }
	        }
	    }
        cout<<ans<<endl;
	}
	return 0;
}
