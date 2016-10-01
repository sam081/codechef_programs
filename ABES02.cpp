#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,arr[1000000];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int b[1000000]=;
        int j=0;
        for(int i=0;i<n;i+=2)
            b[i]=arr[j++];
        if((n)%2==0)
        {
            for(int i=n-1;i>0;i-=2)
                b[i]=arr[j++];
        }
        else
        {
            for(int i=n-2;i>0;i-=2)
                b[i]=arr[j++];
        }
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }
}
