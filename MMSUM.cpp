#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long int a[100000],b[100000];
        int n,index;
        scanf("%d",&n);
        long long int min1;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        	if(a[i]<0)
        		b[i]=1;
        	else
        		b[i]=0;
        }
        long long int sum=a[0],temp;
        //sum of elements of array
 		for(int i=0;i<n;i++)
 		{
 		    min1=0;
 		    int counter=0;
 			temp=0;
 			for(int j=i;j<n;j++)
			{
			    for(int k=i;k<=j;k++)
                {
                    if(b[k]==1 && counter==0)
                    {
                            min1=a[k];
                            index=k;
                            counter++;
                    }
                    if(b[k]==1 && a[k]<min1)
                    {
                        min1=a[k];
                        index=k;
                    }
                }
			    if(j!=index)
                {
                    temp=temp+a[j];
                    if(sum<=temp)
                    {
                        sum=temp;
                    }

                }
			//	printf("%lld %lld\t",temp,sum);
			}
	 	}
        printf("%lld\n",sum);
    }
}
