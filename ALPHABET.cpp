#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    while(n--)
    {
        string s1;
        cin>>s1;
        int x=s1.size();
        int y=s.size();
        int flag=0;
        for(int i=0;i<x;i++)
        {
            flag=0;
            for(int j=0;j<y;j++)
            {
                if(s1[i]==s[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        if(flag==0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}
