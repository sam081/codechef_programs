#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        int arr[105][1000]={0},arr1[1000];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];

            for(int j=1;j<=arr1[i];j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
    /*    for(int i=0;i<n;i++)
        {
            cout<<arr1[i];

            for(int j=1;j<=arr1[i];j++)
            {
                printf("%d ",arr[i][j]);
            }
            cout<<endl;
        }*/
        int index=0,temp=0;;
        for(int i=0;i<n;i++)
        {
            int sum=arr1[i];
            int counter=0;
            int arr2[100]={0};
            for(int j=1;j<=sum;j++)
            {
                    arr2[arr[i][j]]++;
            }

            sort(arr2,arr2+7);

            if(arr2[1]>0)
                for(int j=1;j<4;j++)
                {
                    if(arr2[j]>0 && j==1)
                    {
                        sum+=4*arr2[j];
                        int x=arr2[j];
                        for(int k=0;k<7;k++)
                            arr2[k]-=x;
                    }
                    else if(j==2 && arr2[j]>0)
                    {
                        sum+=2*(arr2[j]);
                        int x=arr2[j];
                        for(int k=0;k<7;k++)
                            arr2[k]-=x;
                    }
                    else if(arr2[j]>0 && j==3)
                    {
                        sum+=1*(arr2[j]);
                        int x=arr2[j];
                        for(int k=0;k<7;k++)
                            arr2[k]-=x;
                    }
                }
            else if(arr2[2]>0)
            {
                for(int j=2;j<4;j++)
                {
                    if(j==2 && arr2[j]>0)
                    {
                        sum+=2*(arr2[j]);
                        int x=arr2[j];
                        for(int k=0;k<7;k++)
                            arr2[k]-=x;
                    }
                    else if(arr2[j]>0 && j==3)
                    {
                        sum+=1*(arr2[j]);
                    }
                }
            }
            else if(arr2[3]>0)
            {
                for(int j=3;j<4;j++)
                {
                    if(arr2[j]>0 && j==3)
                        sum+=arr2[j];
                }
            }
            cout<<sum<<endl;
            if(sum>temp)
            {
                index=i+1;
                temp=sum;
            }
            else if(sum==temp)
            {
                index=-1;
                temp=sum;
            }
        }
        if(index==-1)
            cout<<"tie\n";
        else if(index==1)
            cout<<"chef\n";
        else
            cout<<index<<endl;
    }
}
