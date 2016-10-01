#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long int n;
        scanf("%lld",&n);
        if(n%6==0)
            printf("Misha\n");
        else
            printf("Chef\n");
    }
    return 0;
}
