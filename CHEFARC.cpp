#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int visited[1000][1000];
int bfs(int i,int j,int n,int m)
{
    queue<int> q1;
    queue<int> q2;
    queue<int> dist;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j]=0;
    q1.push(i);
    q2.push(j);
    dist.push(0);
    visited[i][j]=1;
    while(!q1.empty())
    {
       int x1=q1.front();
       int x2=q2.front();
       int d=dist.front();
        if(x1==0 && x2==m-1)
            return dist.front();
        q1.pop();
        q2.pop();
        dist.pop();
            if(arr[x1+1][x2]==0 && x1+1<n && visited[x1+1][x2]==0)
            {
                q1.push(x1+1);
                q2.push(x2);
                visited[x1+1][x2]=d+1;
                dist.push(d+1);
            }
            if(arr[x1-1][x2]==0 && x1-1>=0 && visited[x1-1][x2]==0)
            {
                q1.push(x1-1);
                q2.push(x2);
                visited[x1-1][x2]=d+1;
                dist.push(d+1);
            }
            if(arr[x1][x2+1]==0 && x2+1<m && visited[x1][x2+1]==0)
            {
                q1.push(x1);
                q2.push(x2+1);
                visited[x1][x2+1]=d+1;
                dist.push(d+1);
            }
            if(arr[x1][x2-1]==0 && x2-1>=0 && visited[x1][x2-1]==0)
            {
                q1.push(x1+1);
                q2.push(x2);
                visited[x1][x2-1]=d+1;
                dist.push(d+1);
            }
    }
    return -1;
}
int main()
{

    int test;
    scanf("%d",&test);
    while(test--)
    {
      //  cout<<q1.empty()<<endl;
        int n,m,k1,k2;
        scanf("%d %d %d %d" ,&n,&m,&k1,&k2);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&arr[i][j]);
        if(m==1)
            cout<<0<<endl;
        else
        {
            if(k1==1 && k2==1)
            {
                int ans=bfs(0,0,n,m);
       //     cout<<ans<<endl;
                if(ans%2==0)
                    cout<<ans/2<<endl;
                else if(ans<0)
                    cout<<ans<<endl;
                else
                    cout<<(ans+1)/2<<endl;
            }
            else if(k1==0 & k2==0)
                cout<<-1<<endl;
            else
            {
                int ans=bfs(0,0,n,m);

                if (ans<0)
                    cout<<ans<<endl;
                else if(ans%(k1+k2)==0 && ans>0)
                    cout<<ans/(k1+k2)<<endl;
                else
                    cout<<((ans)/(k1+k2))+1<<endl;
            }
        }

       /* for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<visited[i][j];
                cout<<endl;
                }*/

    }
    return 0;
}
