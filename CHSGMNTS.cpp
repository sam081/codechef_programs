#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,arr[1005];
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        int counter=0;
        /*for(int i=1;i<=n;i++)
                cout<<temp[i]<<" ";*/
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int temp[1005]={0};
                for(int k=i;k<=j;k++)
                {
                    for(int l=j+1;l<=n;l++)
                    {
                        if(arr[l]==arr[k])
                        {
                            temp[k]=1;
                            temp[l]=1;
                        }
                    }
                }
             /*   for(int q=1;q<=n;q++)
                cout<<temp[q]<<" ";
                cout<<endl;*/
                // cout<<l<<"\t"<<upper<<"\n";
                int counter=0;
                for(int k=j+1;k<=n;k++)
                {
                    if(temp[k]==1)
                    {
                        ans=ans+pow(2,counter)-1;
                        counter=0;
                    }
                    else if(k==n)
                    {
                        counter++;
                        ans=ans+pow(2,counter)-1;
                    }
                    else
                    {
                        counter++;
                    }
                }
            //    cout<<"counter:"<<counter<<endl;
              //  cout<<"ans:"<<ans<<endl;
            }
        }
        cout<<ans<<endl;
/*        for(int j=1;j<=n;j++)
            printf("%d ",temp[j]);*/

    }
}
