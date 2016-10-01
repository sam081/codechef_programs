#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string a,b;
        cin>>a>>b;
        int s1=0,s2=0;
        for(int i=0;i<a.size();i++)
        {
            s1=s1*10+(a[i]-'0');
            s1%=9;
        }
        for(int i=0;i<b.size();i++)
        {
            s2=s2*10+(b[i]-'0');
            s2%=9;
        }
        int ans=((s1%9)*(s2%9))%9;
        cout<<ans<<endl;
    }
}
