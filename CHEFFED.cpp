#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,counter2=0;
    scanf("%d",&n);
    for(int i=n;i>=n-200;i--)
    {
        int x=i,sum=0,sumf=i,counter1=0;
        while(x>0)
        {
            if(counter1==2 || sumf>n)
            {
                break;
            }
            sum=sum+x%10;
            x=x/10;
            if(x==0 )
            {
                x=sum;
                sumf=sumf+sum;
                sum=0;
                counter1++;
            }
          //  cout<<i<<"-"<<sumf<<"-"<<x<<"-"<<counter1<<"-"<<counter2<<endl;
        }
        if(sumf==n)
        {
            counter2++;

        }
    }
    cout<<counter2<<endl;
  }
