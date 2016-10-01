#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        char y[1000000],x[1000000];
        scanf("%s",&x);
        scanf("%s",&y);
        long long counter=0,c1=0,c0=0,cm1=0,cm0=0,i=0;
        int len=strlen(x);
        while(len--)
        {
            if(x[i]!=y[i])
            {
                counter++;
                if(x[i]=='1')
                    cm1++;
                else
                    cm0++;
            }
            if(x[i]=='1')
                c1++;
            else
                c0++;
            i++;
        }
     //   cout<<">"<<counter<<endl<<">>"<<cm0<<">>"<<cm1<<"-"<<i<<endl;
        if((c0==i || c1==i))
            printf("Unlucky Chef\n");
        else
        {
            printf("Lucky Chef\n");
        //    cout<<">"<<counter<<endl<<">>"<<cm0<<">>"<<cm1<<"-"<<i<<endl;
            if(cm0>cm1)
                printf("%llu\n",cm0);
            else
                printf("%llu\n",cm1);
        }
    }
}
