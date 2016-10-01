#include<bits/stdc++.h>
using namespace std;
int main()
{
    float x,y,z,w;
    cin>>x;
    cin>>y;
    cin>>z;
    cin>>w;
    if((x/y)==(z/w) || (x/y)==(w/z))
        cout<<"Possible";
    else if((x/w)==(z/y) || (x/w)==(y/z))
        cout<<"Possible";
    else if((x/z)==(w/y) || (x/z)==(y/w))
        cout<<"Possible";
    else
        cout<<"Impossible";
}
