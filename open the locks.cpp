#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin>>n;
    map<int , int> map1;
    map1[2]=1;
    map1[3]=1;
    map1[5]=1;
    map1[7]=1;
    map1[11]=1;
    map1[13]=1;
    map1[17]=1;
    map1[19]=1;
    //cout<<12;
    int dp[10][1000]={0};
    for(int i=0;i<10;i++)
        dp[i][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(map1[j+k]!=1)
                    dp[j][i]=(dp[j][i]+dp[k][i-1])%mod;
            }
        }
    }
    int ans=0;
    for(int j=1;j<=n;j++){
    for(int i=0;i<10;i++)
        cout<<dp[i][j]<<"\t";
        cout<<endl;}
    for(int i=0;i<10;i++)
        ans=(ans+dp[i][n])%mod;
    cout<<ans;
}
