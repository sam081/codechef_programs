#include<bits/stdc++.h>
using namespace std;
bitset<1005> b;
void sieve(int n)
{
    b.set();
    b[0]=b[1]=0;
    for(int i=2;i<n;i++)
    {
        if(b[i])
        {
            for(int j=i*i;j<n;j+=i)
                b[j]=0;
        }
    }
}
int main()
{
    sieve(1005);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,a[10000];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int max1=0;
        for(int i=0;i<n;i++)
        {
            if(b[a[i]])
            {
                if(max1<a[i])
                    max1=a[i];
            }
        }
        if(max1!=0)
            printf("%d\n",max1*max1);
        else
            printf("-1\n");
    }
}
