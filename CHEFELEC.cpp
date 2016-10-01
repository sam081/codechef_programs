// gather all inputs
//mark all 1s
// for zeros in between calculate the minimum combination of two consecutive values

#include<bits/stdc++.h>
using namespace std;
int n,x[100005],y[100005];
char arr[100005];
int cal(int index1,int index2)
{
    int ans=1000000000;
    if(index2-index1>2)
        for(int i=index1+1;i<index2;i++)
        {
            if(i==index1+1)
            {
                ans=min(ans,x[index2]-x[index1+1]);
            }
            if(i==index2-1)
            {
                ans=min(ans,x[index2-1]-x[index1]);
            }
            ans=min(ans,x[index2]-x[i+1]+x[i]-x[index1]);
            cout<<ans<<" ";
        }
    else
        ans=min(x[index2]-x[index2-1],x[index2-1]-x[index1]);
    return ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {

        scanf("%d",&n);
      //  for(int i=0;i<n;i++)
        //    cout<<y[i];
        scanf("%s",&arr);         // signal for electricity
        for(int i=0;i<n;i++)   //coordinates of cities
            scanf("%d",&x[i]);
        int j=0;
        int sum=0;
        for(int i=0;i<n;i++)   //mark all 1s
        {
            if(arr[i]=='1')
                y[j++]=i;
        }
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!='1')
            {
                if(i<y[0])
                    sum=sum+x[i+1]-x[i];
                else if(i>y[j-1])
                    sum=sum+x[i]-x[i-1];
                else
                {
                    cout<<"\ncall";
                    sum=sum+cal(y[k],y[k+1]);
                    k++;
                    i=y[k];
                }
            }
           cout<<endl<<sum<<"-"<<i<<"-"<<y[k]<<"-"<<y[k+1]<<endl;
        }
        cout<<sum<<endl;
        /*for(int i=0;i<n;i++)
            cout<<y[i];*/
    }
}
