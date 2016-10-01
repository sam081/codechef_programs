#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
ll gcd(ll x,ll y)
{
    return y?gcd(y,x%y):x;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        ll arr[100],x=1;
        for(int i=0;i<n;i++)
            scanf("%llu",&arr[i]);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                x=gcd(arr[i],arr[j]);
                if(x!=1)
                {
                    printf("%llu\n",x);
                    break;
                }
            }
        if(x==1)
        {

        }
    }
}
