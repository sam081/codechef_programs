#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
     //   int n,a[200005],b[2][200005],c[2][200005],d[2][200005],f[2][200005];
        int n,a[2000],b[2][2000],c[2][2000],d[2][2000],f[2][2000];
    //    int b1[100005],c1[100005],d1[100005],f[100005];  //change size of array
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int s,e,j=0,temp,temp2,temp3,temp4;
        scanf("%d %d",&s,&e);
            for(int i=s-1;i!=e-1;i++,j++)
            {
                if(j>0)
                    b[0][j]=b[0][j-1]+a[i];
                else
                    b[0][j]=a[i];
            }
            temp=j;
            j=0;
            for(int i=s-2;i!=e-2;i--,j++)
            {
                if(i<0)
                    i=(i+n)%n;
                if(j>0)
                    c[0][j]=c[0][j-1]+a[i];
                else
                    c[0][j]=a[i];
            }
            temp2=j;
            j=0;
            for(int i=e-2;i!=s-2;i--,j++)
            {
                if(j>0)
                    d[0][j]=d[0][j-1]+a[i];
                else
                    d[0][j]=a[i];
            }
            temp3=j;
            j=0;
            for(int i=e-1;i!=s-1;i++,j++)
            {
          //       cout<<i<<"\t";
                if(i>n-1)
                    i=(i)%n;
                if(i==s-1)
                    break;
                if(j>0)
                    f[0][j]=f[0][j-1]+a[i];
                else
                    f[0][j]=a[i];
            }
            temp4=j;
      /*  cout<<temp<<" "<<temp2<<" "<<temp3<<" "<<temp4<<endl;
        cout<<endl<<"b: ";
        for(int i=0;i<temp;i++)
            cout<<b[0][i]<<" ";
        cout<<endl<<"c: ";
        for(int i=0;i<temp2;i++)
            cout<<c[0][i]<<" ";
        cout<<endl<<"d: ";
        for(int i=0;i<temp3;i++)
            cout<<d[0][i]<<" ";
        cout<<endl<<"f: ";
        for(int i=0;i<temp4;i++)
            cout<<f[0][i]<<" ";
*/
        int combmin1=b[0][0],combmin2=c[0][0];
       // cout<<endl<<combmin1<<endl;
        int min1=b[0][0];
        for(j=0;j<temp;j++)
        {
            min1=min(min1,b[0][j]);
            b[1][j]=min1;
        }
        int min2=c[0][0];
        for(j=0;j<temp2;j++)
        {
            min2=min(min2,c[0][j]);
            c[1][j]=min2;
        }
        int min3=d[0][0];
        for(j=0;j<temp3;j++)
        {
            min3=min(min3,d[0][j]);
            d[1][j]=min3;
        }
        int min4=f[0][0];
        for(j=0;j<temp4;j++)
        {
            min4=min(min4,f[0][j]);
            f[1][j]=min4;
        }
  /*      cout<<endl<<"b1: ";
        for(int i=0;i<temp;i++)
            cout<<b[1][i]<<" ";
        cout<<endl<<"c1: ";
        for(int i=0;i<temp2;i++)
            cout<<c[1][i]<<" ";
        cout<<endl<<"d1: ";
        for(int i=0;i<temp3;i++)
            cout<<d[1][i]<<" ";
        cout<<endl<<"f1: ";
        for(int i=0;i<temp4;i++)
            cout<<f[1][i]<<" ";*/
        for(int i=0;i<temp-1;i++)
        {
            combmin1=min(combmin1,b[1][i]+d[1][temp-i-2]);
        }
        for(int i=0;i<temp2-1;i++)
        {
            combmin2=min(combmin2,c[1][i]+f[1][temp2-i-2]);
        }
        //cout<<endl<<combmin1<<" "<<combmin1<<endl;

        int ans=min(c[0][temp2-1],2*min1+c[0][temp2-1]);
        ans=min(ans,c[0][temp2-1]+2*min3);
        ans=min(ans,c[0][temp2-1]+2*combmin1);
        ans=min(ans,2*c[0][temp2-1]+d[0][temp3-1]);
        ans=min(ans,b[0][temp-1]);
        ans=min(ans,2*min2+b[0][temp-1]);
        ans=min(ans,2*min4+b[0][temp-1]);
        ans=min(ans,2*combmin2+b[0][temp-1]);
        ans=min(ans,2*b[0][temp-1]+f[0][temp4-1]);

        cout<<ans<<endl;
    }
}
