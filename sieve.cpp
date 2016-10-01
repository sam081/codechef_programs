#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>

void sieve(ll upperbound)
{ // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        }
} // call this method in main method

bool isPrime(ll N)
{ // a good enough deterministic prime tester
    if (N <= _sieve_size)
        return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0)
            return false;
    return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2


vector<int> primeFactors(ll N)
{ // remember: vi is vector<int>, ll is long long
    vector<int> factors;
    ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N)
    { // stop at sqrt(N); N can get smaller
        while (N % PF == 0)
        {
            N /= PF;
            factors.push_back(PF);
        } // remove PF
        PF = primes[++PF_idx]; // only consider primes!
    }
    if (N != 1)
        factors.push_back(N); // special case if N is a prime
    return factors; // if N does not fit in 32-bit integer and is a prime
} // then ‘factors’ will have to be changed to vector<ll>


int main()
{
    sieve(10000000); // can go up to 10^7 (need few seconds)
    printf("%d\n", isPrime(2147483647)); // 10-digits prime
    printf("%d\n", isPrime(136117223861LL)); // not a prime, 104729*1299709
    // inside int main(), assuming sieve(1000000) has been called before
    vector<int> r = primeFactors(4253); // slowest, 2147483647 is a prime
    for (vector<int>::iterator i = r.begin(); i != r.end(); i++)
        printf("> %d\n", *i);
    r = primeFactors(136117223861LL); // slow, 104729*1299709
    for (vector<int>::iterator i = r.begin(); i != r.end(); i++)
        printf("# %d\n", *i);
    r = primeFactors(142391208960LL); // faster, 2^10*3^4*5*7^4*11*13
    for (vector<int>::iterator i = r.begin(); i != r.end(); i++)
        printf("! %d\n", *i);
}
