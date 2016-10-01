#include<bits/stdc++.h>
using namespace std;
int diff(int tx,int ty,int x,int y)
{
    return (abs(tx-x)+abs(ty-y));
}
int main()
{
        int n,b;
        scanf("%d %d",&n,&b);
        int x[100005],y[100005];
        for(int i=0;i<b;i++)
            scanf("%d",&x[i]);

        for(int i=0;i<b;i++)
            scanf("%d",&y[i]);

        int ans=0;
        for(int i=0;i<b;i++)
        {
            int min1=min(diff(n,n,x[i],y[i]),diff(n,1,x[i],y[i]));
           int  min2=min(min1,diff(1,1,x[i],y[i]));
            min1=min(min2,diff(1,n,x[i],y[i]));
            ans=ans+min1;
        }
        cout<<ans;
}
