#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        map<pair<string,string>, int> map1;
        set<string> start;
        set<string> ending;
        map<string,string> map2;
        int money=0;
        for(int i=0;i<n-1;i++)
        {
            string a,b,c;
            cin>>a>>b>>c;
           // cout<<c.size();
            c[c.length()-1]='\0';
            int x = atoi(c.c_str());
            money+=x;
            if(ending.find(a)==ending.end())
                start.insert(a);
            else
                ending.erase(a);
            if(start.find(b)==start.end())
                ending.insert(b);
            else
                start.erase(b);

            map1[make_pair(a,b)]=x;
            map2[a]=b;
        }
        set<string>::iterator i=start.begin();
        string p=*i;
        for(int j=0;j<n-1;j++)
        {
            string s1=p;
            string s2=map2[s1];
            cout<<s1<<" "<<s2<<" "<<map1[make_pair(s1,s2)]<<"$\n";
            p=s2;
        }
        cout<<money<<"$"<<endl;
    }
}
