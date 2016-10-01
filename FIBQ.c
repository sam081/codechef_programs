#include <stdio.h>
#include<math.h>
#define root5 2.23606797749978969640917366873127623544061835961152572427089
int main(void)
{
	int n,m,a[100000],i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		char c;
		int x,y;
		scanf("%c %d %d",&c,&x,&y);
		if(c=='Q')
		{
			int p,q,r;                  //p=a,q=b,r=c
			p=1/root5;
			q=(1+root5)/2;
			r=(1-root5)/2;
			int prod1=1,prod2=1;
			for(i=x-1;i<y;i++)
			{
				prod1=prod1*(1+pow(q,a[i]));
				prod2=prod2*(1+pow(r,a[i]));
			}
			int ans=p*(prod1-prod2);
			printf("%d\n",ans);
		}
		if(c=='C')
			a[x-1]=y;
	}
}
