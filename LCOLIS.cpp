#include<bits/stdc++.h>
using namespace std;
int fact[11];
int factorial()
{
    fact[0]=1;
    for(int i=1;i<=10;i++)
         fact[i]=fact[i-1]*i;
}
int nCr(int n,int r)
{
    return (fact[n]/(fact[n-r]*fact[r]));
}
int main()
{
    factorial();
    //cout<<fact[1];
    //cout<<nCr(3,2);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        char arr[10][10];
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",&arr[i]);
        int sum=0;
        for(int i=0;i<m;i++)
        {
            int counter=0;
            for(int j=0;j<n;j++)
            {
            //    cout<<i<<endl;
                if(arr[j][i]=='1')
                    counter++;
            }
            if(counter>1)
                sum=sum+nCr(counter,2);
        }
        cout<<sum<<endl;
    }
}
