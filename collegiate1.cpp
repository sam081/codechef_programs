#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        string s;
       // scanf("%d %s",&n,s);
        cin>>n;
        cin>>s;
       // cout<<s[0];
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                counter++;
        }
        //int x=__builtin_popcount(s);
        cout<<counter<<endl;
    }
}
