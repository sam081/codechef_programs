#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;

        cin>>n;
        char p[4];

        scanf("%s",p);
        int a[1000];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        if(n==1 && a[0]%2==0 && p[1]=='e')
            cout<<"Dee\n";
        else
            cout<<"Dum\n";

    }
}
