#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
long long power(long long a,long long b)
{
    ll ans=1;
	while(b!=0)
	{
		if(b%2==1)
            ans=(ans*a)%mod;
		a=(a*a)%mod;
		b=b/2;
	}
	return ans;
}

int main()
{
    int test;
    scanf("%d",&test);
    //factorial
    ll fact[100001];
    for(int i=0;i<=100000;i++)
    {
        if(i>0)
            fact[i]=(fact[i-1]*i)%mod;
        else
            fact[i]=1;
    }
       // cout<<fact[48]<<endl;
    while(test--)
    {
        int n,k;
        long long a[100000],ans=0,count0=0;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%llu",&a[i]);
            if(a[i]==0)
                count0++;
        }
        if(count0>1)
        {
            count0--;
            n=n-count0;
        }
        if(k>n)
            ans=(power(2,n-1))%mod;
        else
        {
            if(k%2==0)
                for(int i=0;i<=k;i+=2){//cout<<">>"<<fact[n]<<" "<<fact[n-i]<<" "<<fact[i]<<endl;
                    //cout<<">>>"<<fact[n]/(fact[n-i]*fact[i])%mod<<"------"<<ans<<endl;
                    ans=(ans+(fact[n]*(power(fact[n-i],mod-2)%mod*power(fact[i],mod-2)%mod)%mod)%mod)%mod;//integer calculation is needed;
                    }
            else
                for(int i=1;i<=k;i+=2)
                    ans=(ans+(fact[n]*(power(fact[n-i],mod-2)%mod*power(fact[i],mod-2)%mod)%mod)%mod)%mod;
        }
        printf("%llu\n",ans);
    }
}
