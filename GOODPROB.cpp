#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100005];// check for the array size
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int f,sum=0;
    for(int i=1;i<n;i++)
    {
        int max1=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if((a[i] & a[j]) == a[i] || (a[i] & a[j]) == a[j])
                f=1;
            else
                f=0;
         //   cout<<f<<": "<<i<<": "<<j<<endl;
            if(a[j]>max1)
                max1=a[j];
            if(f)
                sum=sum+max1;
        }
    }
    cout<<sum;
}
