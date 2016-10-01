#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,ans=-1;
        cin>>n;
        int a[4][10005],b[4][10005];
        for(int i=0;i<n;i++)
        {
            cin>>b[0][i];
            b[1][i]=b[2][i]=b[3][i]=b[0][i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>a[0][i];
            a[1][i]=a[2][i]=a[3][i]=a[0][i];
        }
        int x[4]={0};
        x[0]=a[0][0];
        x[1]=a[0][0]+b[0][0];
        if(n>1)
        {
            x[2]=a[0][0]+b[0][1];
            x[3]=a[0][0]+b[0][0]+b[0][1];
        }
        /*for(int i=0;i<4;i++)
            cout<<x[i]<<endl;
            cout<<endl;*/
        int j=0;

        if(n==1)
            ans=a[0][0]+b[0][0];
        else
        {
            for(int i=0;i<n,j<4;i++)
            {
             //   cout<<"xxx";
                if(a[j][i]!=x[j])
                {
                    if(a[j][i]+b[j][i-1]==x[j] && i-1>=0)
                    {
      //                  cout<<"3-";
                        b[j][i-1]=0;
                        a[j][i]=x[j];
                    }
                     if(a[j][i]+b[j][i]+b[j][i-1]==x[j] || a[j][i]+b[j][i+1]==x[j] )
                    {
                        if(a[j][i+1]!=x[j])
                        {
                            if(a[j][i+1]+b[j][i]==x[j] || a[j][i+1]+b[j][i]+b[j][i+2]==x[j] )
                            {
                                if(a[j][i]+b[j][i+1]==x[j] && i+1<n)
                                {
                    //                cout<<"2-";
                                    b[j][i+1]=0;
                                    a[j][i]=x[j];
                                }
                            }
                            if(a[j][i+1]+b[j][i+1]==x[j])
                            {
                                if(a[j][i]+b[j][i-1]+b[j][i]==x[j] && i-1>=0)
                                {
                               //     cout<<"7-";
                                    b[j][i-1]=0;
                                    b[j][i]=0;
                                    a[j][i]=x[j];
                                }
                            }
                        }
                        else
                        {
                            if(a[j][i+2]!=x[j])
                            {
                                if(a[j][i+2]+b[j][i+1]==x[j] || a[j][i+2]+b[j][i+1]+b[j][i+2]==x[j]  || a[j][i+2]+b[j][i+1]+b[j][i+3]==x[j] || a[j][i+2]+b[j][i+1]+b[j][i+2]+b[j][i+3]==x[j])
                                {
                                    if(a[j][i]+b[j][i-1]+b[j][i]==x[j] && i-1>=0)
                                    {
                                   //     cout<<"7-";
                                        b[j][i-1]=0;
                                        b[j][i]=0;
                                        a[j][i]=x[j];
                                    }
                                }
                            }
                        }
                    }
                    if(a[j][i]+b[j][i-1]+b[j][i]==x[j] && i-1>=0)
                    {
                   //     cout<<"7-";
                        b[j][i-1]=0;
                        b[j][i]=0;
                        a[j][i]=x[j];
                    }
                    if(a[j][i]+b[j][i-1]+b[j][i+1]==x[j] && a[j][i]+b[j][i]==x[j])
                    {
                        if(a[j][i+1]!=x[j])
                        {

                            if(a[j][i+1]+b[j][i]==x[j] || a[j][i+1]+b[j][i]+b[j][i+2]==x[j])
                            {
                                if(a[j][i]+b[j][i-1]+b[j][i+1]==x[j] && i-1>=0 && i+1<n)
                                {
                                  //  cout<<"5-";
                                    b[j][i-1]=0;
                                    b[j][i+1]=0;
                                    a[j][i]=x[j];
                                }
                            }
                            if(a[j][i+1]+b[j][i+1]==x[j] || a[j][i+1]+b[j][i+1]+b[j][i+2]==x[j])
                            {
                                if(a[j][i]+b[j][i]==x[j])
                                {
                      //              cout<<"1-";
                                    b[j][i]=0;
                                    a[j][i]=x[j];
                                }
                            }
                        }
                        else
                        {
                            if(a[j][i+2]!=x[j])
                            {
                                if(a[j][i+2]+b[j][i+1]==x[j] || a[j][i+2]+b[j][i+1]+b[j][i+2]==x[j] || a[j][i+2]+b[j][i+1]+b[j][i+2]+b[j][i+3]==x[j] || a[j][i+2]+b[j][i+1]+b[j][i+3]==x[j])
                                {
                                    if(a[j][i]+b[j][i]==x[j])
                                    {
                          //              cout<<"1-";
                                        b[j][i]=0;
                                        a[j][i]=x[j];
                                    }
                                }
                            }
                        }
                    }
                    if(a[j][i]+b[j][i]==x[j])
                    {
          //              cout<<"1-";
                        b[j][i]=0;
                        a[j][i]=x[j];
                    }
                    if(a[j][i]+b[j][i-1]+b[j][i+1]==x[j] && i-1>=0 && i+1<n)
                    {
                      //  cout<<"5-";
                        b[j][i-1]=0;
                        b[j][i+1]=0;
                        a[j][i]=x[j];
                    }
                    if(a[j][i]+b[j][i]+b[j][i+1]==x[j] && i+1<n)
                    {
                     //   cout<<"6-";
                        b[j][i]=0;
                        b[j][i+1]=0;
                        a[j][i]=x[j];
                    }
                    if(a[j][i]+b[j][i+1]==x[j] && i+1<n)
                    {
        //                cout<<"2-";
                        b[j][i+1]=0;
                        a[j][i]=x[j];
                    }
                    if(a[j][i]+b[j][i-1]+b[j][i+1]+b[j][i]==x[j] && i-1>=0 && i+1<n)
                    {
                 //       cout<<"8-";
                        b[j][i]=0;
                        b[j][i-1]=0;
                        b[j][i+1]=0;
                        a[j][i]=x[j];
                    }
                }
                if(a[j][i]!=x[j])
                {
               //     cout<<"a-";
                    i=-1;
                    if(j==3)
                        i=-2;
                    j++;
                }
                if(i==n-1)
                {
             //       cout<<"b-";
                    if(a[j][i]>ans)
                        ans=a[j][i];

                    if(j<=3)
                    {
              //          cout<<"xx";
                        i=-1;j++;
                    }
                }
                if(j==3 && i==-2)
                {
              //      cout<<"c-";
                    ans=-1;
                    break;
                }
        //        cout<<endl<<"-------------"<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
