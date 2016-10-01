#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,s1,t1;
    cin>>s;
    cin>>t;
    int test;
    cin>>test;
    while(test--)
    {
        s1=s;
        t1=t;
        int k,a,b,c,d;
        scanf("%d %d %d %d %d",&k,&a,&b,&c,&d);
        int counter=0,flag=0;
        c=c-1;d=d-1;
        a=a-1;b=b-1;
        int a1=a,c1=c;
        int b1=b,d1=d;
        for(int i=0;a<b;i++)
        {
            if(counter>k)
            {
                flag=1;
                break;
            }
            if(s1[a]!=t1[c])
            {
                swap(t1[c],t1[c+1]);
                counter++;
                if(s1[a]!=t1[c])
                {
                    flag=1;
                    break;
                }
            }
            c++;a++;
        }
        if(flag==1)
        {
            s1=s;t1=t;
            flag=0;
            counter=0;
            for(int i=0;a1<b1;i++)
            {
                if(counter>k)
                {
                    flag=1;
                    break;
                }
                if(s1[b1]!=t1[d1])
                {
                    swap(t1[d1],t1[d1-1]);
                    counter++;
                    if(s1[b1]!=t1[d1])
                    {
                        flag=1;
                        break;
                    }
                }
                d1--;b1--;
            }
        }
        if(flag==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
