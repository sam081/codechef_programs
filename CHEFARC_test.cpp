#include<bits/stdc++.h>
using namespace std;
int arr[10][10]={
    {0,0,1,0,0,0,   1,1,1,1},
    {0,0,0,1,0,0,   1,1,1,1},
    {0,1,1,1,0,0,   1,1,1,1},
    {0,0,0,0,0,0,   1,1,1,1},
    {0,0,1,1,1,0,   1,1,1,1},
    {0,0,0,0,0,0,   1,1,1,1},

    {1,1,1,1,1,1,   1,1,1,1},
    {1,1,1,1,1,1,   1,1,1,1},
    {1,1,1,1,1,1,   1,1,1,1},
    {1,1,1,1,1,1,   1,1,1,1},
};
int sol[10][10]={0},sol2[10][10]={0};
bool findpath(int x,int y,int n,int m,char direction)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(x==0 && y==m-1)
    {
        sol[x][y]=1;
        return true;
    }
    if(arr[x][y]==1)
        return false;
    sol[x][y]=1;
    if(direction!='u' && findpath(x+1,y,n,m,'d')==true)
        return true;
    if(direction!='l' && findpath(x,y+1,n,m,'r')==true)
        return true;
    if(direction!='d' && findpath(x-1,y,n,m,'u')==true)
        return true;
    if(direction!='r' && findpath(x,y-1,n,m,'l')==true)
        return true;
    sol[x][y]=0;
    return false;
}
bool findpath2(int x,int y,int n,int m,char direction)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(x==0 && y==0)
    {
        sol2[x][y]=2;
        return true;
    }
    if(sol[x][y]==0)
        return false;
    sol2[x][y]=2;
    if(direction!='d' && findpath2(x-1,y,n,m,'u')==true)
        return true;
    if(direction!='l' && findpath2(x,y+1,n,m,'r')==true)
        return true;

    if(direction!='u' && findpath2(x+1,y,n,m,'d')==true)
        return true;
    if(direction!='r' && findpath2(x,y-1,n,m,'l')==true)
        return true;
    sol2[x][y]=0;
    return false;
}
int main()
{

    int test=1;
   // scanf("%d",&test);
    while(test--)
    {
        int n=6,m=6;
     //   scanf("%d %d",&n,&m);
     /*   for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&arr[i][j]);*/
      //  arr[1][m-1]=2;
        findpath(0,0,n,m,'d');
        findpath2(0,m-1,n,m,'d');
//        cout<<bfs(0,0,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                printf("%d ",sol[i][j]);
                cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                printf("%d ",sol2[i][j]);
                cout<<endl;
        }
    }
    return 0;
}
