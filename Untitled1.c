//calculate the max in each column
//calculate cumulative sum in each column
//sam_081
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n,m,maxc;
    scanf("%d %d",&n,&m);
    ll arr[n][m],sum[n][m],maxcol[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%llu",&arr[i][j]);
            if(j==0)
            {
                sum[i][j]=arr[i][j];
                maxc=arr[i][j];
            }
            else
                sum[i][j]=sum[i][j-1]+arr[i][j];
            if(arr[i][j]>maxc)
                    maxcol[i][j]=arr[i][j];
            else
                    maxcol[i][j]=maxc;
        }
    }
    cout<<"-----------\n";
    int q,x;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&x);
        for(int i=0;,i<i+x+x<n;i++)
        {
            for(int j=0;j+x<m;j++)
                printf("%d\n",arr[i][j]);
            cout<<endl;
        }
    }
    return 0;
}
