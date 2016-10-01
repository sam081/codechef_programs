#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    long long int a[100000];
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    long long int max1;
    long long int min1=max1=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<min1)
            min1=a[i];
        if(a[i]>max1)
            max1=a[i];
    }
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t<min1 || t>max1)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
