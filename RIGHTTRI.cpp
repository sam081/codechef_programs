#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long h,s;
        scanf("%llu %llu",&h,&s);
        double a,b;
        a=(sqrt(pow(h,2)+4*s)+sqrt(pow(h,2)-4*s))/2;
        b=(sqrt(pow(h,2)+4*s)-sqrt(pow(h,2)-4*s))/2;
        if(a>0 && b>0)
        {
            if(a>b)
                printf("%f %f %f\n",b,a,(double)h);
            else
                printf("%f %f %f\n",a,b,(double)h);
        }
        else
            cout<<"-1\n";
    }
}
