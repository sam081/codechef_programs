#include<bits/stdc++.h>
using namespace std;
int main()
{

    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long k,i,temp=0,j,n,x=0,y=1;
        scanf("%llu",&k);
        while(1)
        {
            y=1;temp=0;
            for(int i=0;;i++)
            {
                if(y>k)
                    break;
                n=y;
                j=temp;
                y=(long long)pow(5,i);
                temp=i;
            }
            //cout<<"1";
            if(k<=5)
            {
         //       cout<<"2";
                x=x+2*(k-1);
                break;
            }
            else
            {
                cout<<k;
                x=x+2*pow(10,j)*((k-1)/n);
                k=(k)-((k-1)/n)*n;
            }
        }
        printf(">>%llu\n",x);
    }

}
