#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        ll n,m,b;
        ll sum=0;
        cin>>n>>b>>m;
        while(n>=1)
        {
            if(n%2==0)
            {
                sum+=m*(n/2)+b;
                n=n/2;
                m=2*m;
            }
            else
            {
                sum+=m*(n+1)/2 +b;
                n=n-(n+1)/2;
                m=2*m;
            }
        }
        cout<<sum-b<<endl;
    }
}
