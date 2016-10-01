#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,arr[1005]={0};
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int temp;
            scanf("%d",&temp);
            arr[temp]++;
        }
        int counter=0,i1=0,i2=0;
        for(int i=1;i<=1004;i++)
        {
            if(arr[i]>=4)
            {
               // cout<<"a\n";
                i1=i2=i;
            }
            if(arr[i]>=2)
            {
             //   cout<<"b\n";
                i1=i2;
                i2=i;
                //counter++;
            }
            //cout<<">>"<<ans<<endl;
           // cout<<i1<<"-"<<i2<<endl;
        }
       // cout<<i1<<endl<<i2<<endl;
        if(i1*i2>0)
            cout<<i2*i1<<endl;
        else
            cout<<"-1\n";
    }
}
