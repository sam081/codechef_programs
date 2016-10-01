#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,a,b;
        vector< vector<int> > v;
        vector<int> f;
        cin>>n;
        int sum=0;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&a);
                for(int j=1;j<=a;j++)
                {
                    scanf("%d",&b);
                    f.push_back(b);
                }
                v.push_back(f);
                sum+=a;
            }
        int fi;
        f.clear();
        for(int i=1;i<=sum;i++)
        {
            scanf("%d",&fi);
            f.push_back(fi);
        }
        int flag=0;
        for(vector<int>::iterator i=f.begin();i!=f.end();i++)
        {
            //for(int i=0;i<n;i++)
            for(vector<int>::iterator j=i.begin();j!=i.end();j++)
            {
                if(*i==v[i].front)
                    v[i].pop_back();
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}
