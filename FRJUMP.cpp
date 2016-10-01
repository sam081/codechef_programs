#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;
typedef long long ll;
double logvalues[100001],logsum[100001];
ll fi[100001],f;
void update(int p,int n)
{

    logvalues[p]=log10(fi[p]);
    for(int j=1;j<=n;j++)
    {
        double x=0;
        for(int i=1;i<=n;i+=j)
            x=x+logvalues[i];
        logsum[j]=x;
    }
}
int main()
{
    int n,q,p,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%llu",&fi[i]);
        logvalues[i]=log10(fi[i]);
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i+=j)
            logsum[j]=logsum[j]+logvalues[i];
    }

   /* for(int i=1;i<=n;i++)
        cout<<logsum[i]<<" ";
        cout<<"-----------------\n";
    for(int i=1;i<=n;i++)
        cout<<logvalues[i]<<" ";*/
    scanf("%d",&q);
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d %llu",&p,&f);
            fi[p]=f;
            update(p,n);
        }
        else
        {
            float s;
            ll ans=1;
            scanf("%d",&r);
            for(int i=0;(1+i*r)<=n;i++)
                ans=(ans*fi[1+i*r])%mod;
            if(r<=n)
                {
                    s=pow(10,logsum[r]-floor(logsum[r]));
                    s=s+0.000000000001;
                }
            else
            {
                s=pow(10,logvalues[1]-floor(logvalues[1]));
                s=s+0.000000000001;
            }
           // cout<<">>"<<logsum[r]<<">>"<<floor(logsum[r])<<endl;
            printf("%d %llu\n",(int)(s),ans);
        }
    }
}
