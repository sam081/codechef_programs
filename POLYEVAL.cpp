#include<bits/stdc++.h>
using namespace std;
#define mod 786433
int power[250005];
int n,arr[250005];
long long horner(int input)
{
    long long b[250005];
    for(int i=n;i>=0;i--)
    {
        if(i==n)
            b[i]=arr[i];
        else
            b[i]=(arr[i]+(b[i+1]*input)%mod)%mod;
    }
    return b[0];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int input;
        scanf("%d",&input);
        long long ans=horner(input);
        printf("%llu\n",ans%mod);
    }
}
