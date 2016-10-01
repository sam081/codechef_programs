#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        char x[100000],y[100000],temp[100000],temp1[100000];
        scanf("%s",&x);
        scanf("%s",&y);
        n=strlen(x);
        for(int i=0;i<n;i++)
        {
            if(x[i]=='W')
                temp[i]='B';
            if(x[i]=='B')
                temp[i]='W';
            if(y[i]=='W')
                temp1[i]='B';
            if(y[i]=='B')
                temp1[i]='W';
        }
        int z=strcmp(temp,temp1);
        if(z<=0)
            printf("%s\n",temp);
        else
            printf("%s\n",temp1);
    }
    return 0;
}
