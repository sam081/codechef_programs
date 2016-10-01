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
        int l=s.length();
        int flag=0;
        if(l%2==0)
        {
            int mid=l/2;
            for(int i=0;i<mid;i++)
            {
                if(s[i]=='.' && s[l-1-i]=='.')
                    s[i]=s[l-1-i]='a';
                else if(s[i]=='.')
                    s[i]=s[l-1-i];
                else if(s[l-1-i]=='.')
                    s[l-1-i]=s[i];
                else if(s[l-1-i]!=s[i])
                {
                    flag=1;
                    break;
                }
            }
        }
        else
        {
            int mid=l/2;
            for(int i=0;i<mid;i++)
            {
                if(s[i]=='.' && s[l-i-1]=='.')
                    s[i]=s[l-1-i]='a';
                else if(s[i]=='.')
                    s[i]=s[l-1-i];
                else if(s[l-1-i]=='.')
                    s[l-1-i]=s[i];
                else if(s[l-1-i]!=s[i])
                {
                    flag=1;
                    break;
                }
                else if(s[mid]=='.')
                    s[mid]='a';
            }
        }
        if(s[l/2]=='.')
            s[l/2]='a';
        if(flag==0)
            cout<<s<<endl;
        else
            cout<<-1<<endl;
    }
}
