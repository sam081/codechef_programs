#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    return y? gcd (y , x%y):x;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        ll n;
        scanf("%llu",&n);
        ll path=4*n;
        ll steps=n+1;
        ll lcm = path / gcd(path,steps) *steps;
        printf("%llu\n",lcm/steps);
    }
}
