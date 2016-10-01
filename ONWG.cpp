#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005]={0};
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            if(i%2)
                for(int j=0;j<m;j+=2)
                {
                 arr[i][j]=1;
                }
            else
                for(int j=1;j<m;j+=2)
                {
                    arr[i][j]=1;
                }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int counter;
            if(!(i%2))
            {
                for(int j=0;j<m;j+=2)
                {
                    counter=0;
                    if(arr[i][j+1]>0 && j+1<m)
                        counter++;
                    if(arr[i+1][j]>0 && i+1<n)
                        counter++;
                    if(arr[i-1][j]>0 && i-1>=0)
                        counter++;
                    if(arr[i][j-1]>0 && j-1>=0)
                        counter++;
                   // cout<<counter<<"1"<<endl;
                    sum=sum+counter;
                    arr[i][j]=1;
                }
            }
            else
            {
                for(int j=1;j<m;j+=2)
                {
                    counter=0;
                    if(arr[i][j+1]>0 && j+1<m)
                        counter++;
                    if(arr[i+1][j]>0 && i+1<n)
                        counter++;
                    if(arr[i-1][j]>0 && i-1>=0)
                        counter++;
                    if(arr[i][j-1]>0 && j-1>=0)
                        counter++;
                    //cout<<counter<<"-1"<<endl;
                    sum=sum+counter;
                    arr[i][j]=1;
                }
            }
        }
        cout<<sum;
    }
}
