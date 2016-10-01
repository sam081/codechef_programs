#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<pair<int,int>, pair<int,int>> map1;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        map1[make_pair(a,b)]=make_pair(c,d);
    }
}
