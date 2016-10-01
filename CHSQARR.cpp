#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int arr[1001][1001];
int aux[1001][1001]={0};
int Max[1001][1001];
int Max2[1001][1001];

int main()
{
    int n,m,maxc;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&arr[i][j]);
    //auxiliary matrix for sum of submatrices

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            aux[i][j]=aux[i][j-1]+arr[i][j];

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            aux[j][i]=aux[j-1][i]+aux[j][i];
/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
                    printf("%d ",aux[i][j]);

            }
            cout<<"\n";
    }
    cout<<"-----------\n";*/
    int q,x,y;
    scanf("%d",&q);
    while(q--)
    {

        scanf("%d %d",&x,&y);
        //x*y*max-sum
        int sum,i;
        for(int j=1;j<=n;j++)
        {
            int index=1;
            deque<int> Q;
            for(i=1;i<=y;i++)
            {
                while((!Q.empty()) && arr[j][i]>arr[j][Q.back()])
                    Q.pop_back();
                Q.push_back(i);
            }
            Max[j][index]=arr[j][Q.front()];
            for(;i<=m;i++)
            {

                while((!Q.empty()) && Q.front()<=i-y)
                    Q.pop_front();
                while((!Q.empty()) && arr[j][i]>arr[j][Q.back()])
                    Q.pop_back();
                Q.push_back(i);
                Max[j][++index]=arr[j][Q.front()];
            }
            //cout<<arr[j][Q.front()]<<endl;
        }
        for(int j=1;j<=m;j++)
        {
            int index=1;
            deque<int> Q;
            //Q.push_back(0);
            for(i=1;i<=x;i++)
            {
                while((!Q.empty()) && Max[i][j]>=Max[Q.back()][j])
                    Q.pop_back();
                Q.push_back(i);
            }
            Max2[index][j]=Max[Q.front()][j];
            for(;i<=n;i++)
            {

                while((!Q.empty()) && Q.front()<=i-x)
                    Q.pop_front();
                while((!Q.empty()) && Max[i][j]>=Max[Q.back()][j])
                    Q.pop_back();
                Q.push_back(i);
                Max2[++index][j]=Max[Q.front()][j];
            }
            //cout<<arr[j][Q.front()]<<endl;
        }
/*        for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<Max[i][j]<<" ";
            cout<<endl;
        }*/

        int ans=1000000000;
        for(int i=1,k=x;i<=n,k<=n;i++,k++)
        {
            for(int j=1,l=y;j<=m,l<=m;j++,l++)
            {
                sum=aux[k][l] - aux[i-1][l] - aux[k][j-1] + aux[i-1][j-1];
               int xymax=x*y*Max2[i][j];
                ans=min(ans,xymax-sum);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
