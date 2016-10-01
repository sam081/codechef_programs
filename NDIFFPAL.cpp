#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        char a[10000],b[10000];
        scanf("%d",&n);
        if(n==1)
            printf("a\n");
        else if(n==2)
            printf("ab\n");
        else if(n==3)
            printf("aa\n");
        else
        {
            a[0]='a';
            int p=3,i;
            for(i=1;i<n;i++)
            {
                int l=strlen(a);
                if(l%2==0)
                {
                    if(p+3<=n)
                    {
                        a[i]=a[0];
                        p=p+3;
                    }
                    else
                    {
                        a[i]='x';
                        p=p+1;
                    }
                }
                else
                {
                    if(p+2<=n)
                    {
                        a[i]=a[i-1];
                        p=p+2;
                    }
                    else
                    {
                        a[i]='y';
                        p=p+1;
                    }
                }
            }
            for(int j=0;j<n;j++)
            {
                if(j<i)
                    b[j]=a[j];
                else
                    b[j]=a[i--];
            }
        }
        printf("%s",b);
    }
    return 0;
}
