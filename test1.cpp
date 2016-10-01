/*

Saurabh Joshi

PDPM IIITDM Jabalpur

*/
#include<bits/stdc++.h>
#define LL long long int
//#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i];
#define endl "\n"
using namespace std;
deque<int>q;
int MAXI[1001][1001];
int FINAL_MAXI[1001][1001];
int A[1001][1001];
int ROW[1001][1001]={0};
int COL[1001][1001]={0};
int N,M;
void maximize(int idx,int k)
	{
		int i;
		int index = 0;
		q.push_back(1);
		for(i=2;i<=k;++i)
			{
				while(!q.empty()&& A[idx][i] > A[idx][q.back()] )
					q.pop_back();
				q.push_back(i);
			}
		MAXI[idx][++index] = A[idx][q.front()];
        for(i=k+1;i<=M;++i)
		{
				while(!q.empty()&&q.front()<=i-k)
					q.pop_front();
				while(!q.empty()&&A[idx][i]>A[idx][q.back()])
				q.pop_back();
				q.push_back(i);
				MAXI[idx][++index] = A[idx][q.front()];
			}
		while(q.empty()==0)
			q.pop_back();
	}

void maximizes(int idx,int k)
	{
		int i;
		int index = 0;
		q.push_back(1);
		for(i=2;i<=k;++i)
			{
				while(!q.empty()&&MAXI[i][idx]>MAXI[q.back()][idx])
					q.pop_back();
				q.push_back(i);
			}
		FINAL_MAXI[++index][idx] = MAXI[q.front()][idx];
		for(i=k+1;i<=N;++i)
			{
				while(!q.empty()&&q.front()<=i-k)
					q.pop_front();
				while(!q.empty()&&MAXI[i][idx]>MAXI[q.back()][idx])
					q.pop_back();
				q.push_back(i);
				FINAL_MAXI[++index][idx] = MAXI[q.front()][idx];
			}
		while(q.empty()==0)
			q.pop_back();
	}
int getsum(int a,int b,int c,int d)
	{
		int sum = ROW[c][d]-ROW[a-1][d]-ROW[c][b-1]+ROW[a-1][b-1];
		return sum;
	}
int getmax(int a,int b,int c,int d)
	{
		int maximum;
		maximum = FINAL_MAXI[a][b]*(c-a+1)*(d-b+1);
		return maximum;
	}
int f(int a,int b)//returns minimum operations to make beautiful
	{
		int i,j,k,l,x,y;
		int ans = 1000000000;
		for(i=1,k=a;i<=N,k<=N;++i,++k)
			{
				for(j=1,l=b;j<=M,l<=M;++j,++l)
					{
		//				cout<<i<<" "<<j<<" "<<k<<" "<<l<<" ";
						x = getsum(i,j,k,l);
						y = getmax(i,j,k,l);
		//				cout<<x<<" "<<y<<endl;
						ans = min(ans,0-getsum(i,j,k,l)+getmax(i,j,k,l));
					}
			}
		return ans;
	}
int main()
{
	int i,j,a,b,q;
    ios_base::sync_with_stdio(0);
	cin>>N>>M;
		rep(i,1,N)
			rep(j,1,M)
				{
					cin>>A[i][j];
					ROW[i][j] = ROW[i][j-1] + A[i][j];
				}
        cout<<"-------\n";
        rep(i,1,N)
        {
            rep(j,1,M)
                cout<<ROW[i][j]<<" ";
            cout<<endl;
        }
        cout<<"-------\n";
		rep(j,1,M)
			rep(i,1,N)
				ROW[i][j] = ROW[i-1][j] + ROW[i][j];
        rep(i,1,N)
        {
            rep(j,1,M)
                cout<<ROW[i][j]<<" ";
            cout<<endl;
        }
        cout<<"-------\n";
		cin>>q;
		int k;
		while(q--)
			{
				cin>>a>>b;
				for(i=1;i<=N;++i)
                {
                    maximize(i,b);
                    rep(k,1,N)
                    {
                        rep(j,1,M)
                            cout<<A[i][j]<<" ";
                        cout<<endl;
                    }
                    cout<<"---\n";
                }

                cout<<"maximizes\n";
				//now i have maximum of all horizontal subarrays in O(n)
				//now i need to calculate the maximum of horizontal in vertical subarrays of size a
				for(i=1;i<=M-b+1;i++)
					{
						maximizes(i,a);
				        rep(k,1,N)
                        {
                            rep(j,1,M)
                                cout<<ROW[i][j]<<" ";
                            cout<<endl;
                        }
                        cout<<"---\n";
					}

				for(i=1;i<=N-a+1;i++)
					{
						for(j=1;j<=M-b+1;j++)
							cout<<FINAL_MAXI[i][j]<<" ";
						cout<<endl;
					}
				cout<<f(a,b)<<endl;
			}
	}
