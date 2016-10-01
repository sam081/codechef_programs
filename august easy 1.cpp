#include<bits/stdc++.h>
using namespace std;
int arr[100000];
typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

set<int> primeFactors(ll N)
{
    set<int> factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N)
    {
        while (N % PF == 0)
        {
            N /= PF;
            factors.insert(PF);
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
        factors.insert(N);
    return factors;
}
int digits(int x)
{
    int counter=0;
    while(x>0)
    {
        x=x/10;
        counter++;
    }
    return counter;
}
int main()
{
   // cout<<digits(12);

    sieve(100000);
    for(int i=2;i<=100000;i++)
    {
        int counter=0;
        set<int> x=primeFactors(i);
        arr[i]=x.size();
    }
    int b[100000];
    b[1]=1;b[0]=0;
    for(int j=2;j<=100000;j++)
    {
        int x=digits(j);
        if(x==arr[j])
            b[j]=1;
        else
            b[j]=0;
    }
    int c[100000];
    int temp=0;
    for(int i=1;i<=100000;i++)
    {
        if(b[i]==1)
            c[i]=c[i-1]+1;
        else
            c[i]=c[i-1];

    }
    int test;
    cin>>test;
    while(test--)
    {
        int a,d;
        cin>>a>>d;
        cout<<c[d]-c[a-1]<<endl;
    }
}
