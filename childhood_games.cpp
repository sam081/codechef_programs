#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int start[10000][3],ending[10000][3];
    for(int i=0;i<n;i++)
    {
        cin>>start[i][0]>>start[i][1]>>ending[i][0]>>ending[i][1];
        start[i][2]=ending[i][2]=0;
    }
    int flag,counter=1;
    for(int i=0;i<n;i++)
    {
        if(start[i][2]!=1)
        {
            start[i][2]=1;
            for(int j=1;j<n;j++)
            {
                flag=0;
                if(ending[i][0]==start[j][0] && ending[i][1]==start[j][1] && start[j][2]!=1)
                {
                    cout<<2<<"--";
                    counter++;
                    start[j][2]=1;
                    ending[j][2]=1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
            break;
    }
    if(flag==0)
        cout<<"NO";
    else if(counter==n)
        cout<<"YES";
}
