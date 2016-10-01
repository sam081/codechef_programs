#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        string s;
        cin>>s;
        int zeros=0;
        int ones=0;
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            if(s[i]=='0')
                zeros++;
            else
                ones++;
        }
        if(ones==1 || zeros==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
