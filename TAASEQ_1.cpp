#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,arr[10000];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int diff=arr[2]=arr[1];
        for(int i=0;i<n;i++)
        {
            if(arr[i]-arr[i-1]!=diff)
            {
                int x=arr[i];

            }
        }
    }
}
