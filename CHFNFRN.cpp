#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=1;
            }
        }

        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            arr[a-1][b-1]=arr[b-1][a-1]=0;
        }
        set <int> set1;
        set <int> set2;
        set <int>::iterator it;
        int Ver=n,src=0;
        int arr2c[Ver];
        for (int i = 0; i < Ver; ++i)
            arr2c[i] = -1;
        arr2c[src] = 1;
        for(int i=0;i<n;i++)
            set1.insert(i);
        queue <int> q;
        q.push(src);
        int flag=0;
        while(set1.size()!=0){
            flag=0;
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            for (int b= 0; b< Ver; ++b)
            {
                if (arr[a][b] && arr2c[b] == -1)
                {
                    arr2c[b] = 1 - arr2c[a];
                    q.push(b);
                    set1.erase(a);
                    set1.erase(b);
                }
                else if (arr[a][b] && arr2c[b] == arr2c[a] &&flag!=1)
                {
                    flag=1;
                    set2.insert(flag);
                    break;
                }
            }
        }

        if (flag==0)
            set2.insert(0);
        if(set1.size()!=0)
        {
            it=set1.begin();
            q.push(*it);
            set1.erase(*it);
        }
        }
        it=set2.begin();
        if(set2.size()==1 and *it==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
