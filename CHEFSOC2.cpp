#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m,s;
        int a[5],arr[5][5];
        scanf("%d %d %d",&n,&m,&s);
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        //dp array construction
        //cout<<"asa\n";
        for(int i=0;i<m;i++)
            printf("%d",a[i]);
            printf("\n");
        for(int j=0;j<m+1;j++)
        {
            printf("%d out \n",a[j-1]);
            for(int i=1;i<=n;i++)
            {
                printf("%d inner\n",a[j-1]);
                if(j==0)
                {
                    arr[i][j]=0;
                    if(i==s)
                        arr[i][j]=1;
                    printf("%d ",arr[i][j]);
                }
                else
                {
                    printf("%d 1sssin\n",a[j-1]);
                    if ((i+a[j-1])>n )
                        arr[i+a[j-1]][j-1]=0;
                    printf("%d 2sssin\n",a[j-1]);
                    if ((i-a[j-1])<=0)
                        arr[i-a[j-1]][j-1]=0;
                        printf("%d 3sssin\n",a[j-1]);

                    arr[i][j]=arr[i+a[j-1]][j-1]+arr[i-a[j-1]][j-1];
                    printf("(%d%d) %d arr[%d][%d]=arr[%d][%d]+arr[%d][%d] \t %d a[%d] \n",i,j,arr[i][j],i,j,i+a[j-1],j-1,i-a[j-1],j-1,a[j-1],j-1);
                }
            }
            printf("\n");
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++)
                printf("%d ",arr[i][j]);
                printf("\n");}

        printf("\n");

                for(int i=0;i<m;i++)
            printf("%d",a[i]);
            printf("\n");

        for(int i=1;i<=n;i++)
        {
            printf("%d ",arr[i][m]);
        }
    }
    return 0;
}
