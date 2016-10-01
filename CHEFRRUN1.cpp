//brute force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,a[2][100005];
        int counter=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[0][i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                a[1][j]=0;
            for(int j=i%n; ; )
            {
                if(a[1][j]==1)
                    break;
                a[1][j]=1;
                j=(j+a[0][j]+1)%n;
                if(j==i)
                    counter++;
            //    cout<<j<<"-->";
            }
        }
        cout<<counter<<endl;
    }
}
