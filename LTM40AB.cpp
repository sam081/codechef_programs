#include<bits/stdc++.h>
using namespace std;
int main()
{

    int test;
    cin>>test;
    while(test--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        long long sum=0;
        for(int i=a;i<=b;i++)
        {
            if(i<d)
            {
                if(i<c)
                    sum+=d-c+1;
                else if(i>=c)
                    sum+=d-i;

            //    cout<<sum<<"--";
            }
        }
        cout<<sum<<endl;
    }
}
