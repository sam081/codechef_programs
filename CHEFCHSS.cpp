#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int f1,f2,r2,r1,r3,r4;
        float p1,p2,p3,p4;
        scanf("%d %d %d %d %d %d",&f1,&f2,&r1,&r2,&r3,&r4);
        scanf("%f %f %f %f",&p1,&p2,&p3,&p4);
        float sum1=(p1*p2*r1+p1*(1-p2)*r2)-f1;
        float sum2=(p3*p4*(r3+r4)+p3*(1-p4)*r3)-f2;
        if(sum1>sum2)
            cout<<"FIRST\n";
        else if(sum1==sum2)
            cout<<"BOTH\n";
        else
            cout<<"SECOND\n";
    }
}
