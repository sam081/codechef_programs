#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,arr[100000];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int sum=0,x=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==2)
            {
                x=2;
                break;
            }
            else
            {
                sum=sum+arr[i];
                if(arr[i]==5)
                    x=5;
            }
        }
        float avg=(float)sum/(float)n;
        if(x==2 || avg<4 || x==0)
            printf("No\n");
        if(x==5 && avg>=4)
            printf("Yes\n");
    }
    return 0;
}
