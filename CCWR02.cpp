#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int x,k;
        float a[100000],b[100000];
        scanf("%d %d",&x,&k);
        for(int i=0;i<k;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<k;i++)
            scanf("%d",&b[i]);
        float temp=x;
        for(int i=0;i<k;i++)
        {
            temp=temp+(a[i]/b[i])*temp;
        }
        float t=((temp-x)/temp)*100;
        cout<<floor(t)<<endl;
    }
}
