#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz size()
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define SL(n) scanf("%llu",&n)
#define PL(n) printf("%lld ",n)
#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d ",n);
#define _ ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long int LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<VL> VVL;
typedef pair<LL,LL> PLL;
typedef pair<int ,int> II;
typedef pair<double,double> dd;
typedef vector<II> VII;
void FastIO()
{
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
}
PLL tree[100005];
int main()
{
    LL i,n,w,l,mid,s,r,sum,low,high;
    cin >> n >> w >> l;
    for(i=0;i<n;i++)
        SL(tree[i].ff) , SL(tree[i].ss);
    low = 0 , high = 1000000000000000000LL;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        sum = 0;
        printf("%lld %lld %lld lmh\n",low,mid,high);
        for(i=0;i<n;i++)
        {
            r = mid*tree[i].ss ;
            s = tree[i].ff + r ;
            sum+= ( s>= l ? s : 0);
            printf("%d cond\n",sum>=w);
            printf("%lld %lld %lld rssum\n",r,s,sum);
            if(sum>=w)
                break;
            printf("break\n");
        }
        printf("\n");
        if(sum>=w)
            high = mid-1;
        else
            low = mid+1;
    }
    cout << low << endl;
    return 0;
}
