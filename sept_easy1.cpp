#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n,a[20001],arr[20001]={0};
        set<int> dist,t;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            dist.insert(a[i]);
        int len=dist.size();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                arr[a[j]]+=1;
                t.insert(a[j]);
                if((t.size())==len)
                    counter++;
            }
            arr[a[i]]-=1;
            if(arr[a[i]]==0)
                t.erase(a[i]);
        }
        cout<<counter;
}
