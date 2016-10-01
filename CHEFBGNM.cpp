#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,arr[100005][3];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&arr[i][0],&arr[i][1]);// 0=f 1=d
            if(i==0)
                arr[i][2]=arr[i][0];
            else
                arr[i][2]=arr[i-1][2]+arr[i][0];
        }
        for(int i=1;i<=arr[n-1][2];i++)
        {
            for(int j=i;j<=arr[n-1][2];j++)
            {
                if(i<arr[k][3])
            }
        }
    }
}
