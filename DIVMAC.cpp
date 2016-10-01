#include<bits/stdc++.h>
using namespace std;
int tree[100000],A[100000],lazy[100000],B[100000];
void build(int node, int start, int end1)
{
    if(start == end1)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end1) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end1);
        // Internal node will have the sum of both of its children
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}

void updateRange(int node, int start, int end1, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node]=max(tree[node], lazy[node]);    // Update it
        if(start != end1)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end1 || start > r || end1 < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l && end1 <= r)
    {
        // Segment is fully within range
        tree[node] = max(val,tree[node]);
        if(start != end1)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end1) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end1, l, r, val);   // Updating right child
    tree[node] = max(tree[node*2],tree[node*2+1]);        // Updating root with max value
}

int queryRange(int node, int start, int end1, int l, int r)
{
    if(start > end1 || start > r || end1 < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += lazy[node];            // Update it
        if(start != end1)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l && end1 <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end1) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end1, l, r); // Query right child
    return max(p1,p2);
}
bitset<1000000> bs;
vector<int> primes;
typedef long long ll;
void sieve(ll upperbound)
{ // create list of primes in [0..upperbound]
    int _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (int i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (int j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        }
}
int min_pr_fac(int x)
{
    for(vector<int>::iterator i=primes.begin();i!=primes.end();i++)
    {
        if(x%*i==0)
            return *i;
    }
}
int max_of_min(int L,int R)
{
    int ans=0;
    for(int i=L;i<=R;i++)
    {
        int x=min_pr_fac(B[i]);
        B[i]=B[i]/x;
        if(B[i]==1)
            A[i]=B[i];
        else
            A[i]=min_pr_fac(B[i]);
        ans=max(ans,x);
    }
    return ans;
}
int main()
{
    sieve(10000);
   // for(vect||<int>::iterator i=primes.begin();i!=primes.end();i++)
     //   cout<<*i
   // cout<<primes.size();
   // cout<<min_pr_fac(10);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int X;
            scanf("%d",&B[i]);
            if(B[i]!=1)
                A[i]=min_pr_fac(B[i]);
            else
                A[i]=B[i];
        }
        for(int i=1;i<15;i++)
            cout<<A[i]<<" ";
            cout<<endl;
        build(1,1,n);
        for(int i=1;i<15;i++)
            cout<<tree[i]<<" ";
        cout<<endl;
        for(int i=1;i<15;i++)
            cout<<lazy[i]<<" ";
        while(m--)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int L,R;
                //int end1=A.size();
                scanf("%d %d",&L,&R);
                updateRange(1,1,n,L,R,max_of_min(L,R));
                for(int i=1;i<15;i++)
                    cout<<A[i]<<" ";
                    cout<<endl;
                for(int i=1;i<15;i++)
                    cout<<tree[i]<<" ";
                cout<<endl;
                for(int i=1;i<15;i++)
                    cout<<lazy[i]<<" ";
                    cout<<endl;
            }
            if(type==1)
            {
                int L,R;
              //  int end1=A.size();
                scanf("%d %d",&L,&R);
                int x=queryRange(1,1,n,L,R);
                cout<<x;
            }
        }
    }
}
