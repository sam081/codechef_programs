#include<iostream>
#include<math.h>
using namespace std;
#define mm 1000000007
typedef long long lll;

int main()
{
	lll no;
		double logs[10];
	for(int i=1;i<=9;i++)
	{
		logs[i]=log10(i);
//		cout<<logs[i]<<" ";
	}
	cin>>no;
	lll a[no];
	lll queries;
	for(lll i=0;i<no;i++)
			cin>>a[i];
	cin>>queries;
	while(queries--)
	{
		lll qq1;
		cin>>qq1;
		if(qq1==1)
		{
			lll nn1,nn2;
			cin>>nn1;
			cin>>nn2;
			a[nn1-1]=nn2;
		}
		else
		{
			lll rr;
			cin>>rr;
			lll i=1,aans=1;
			double aans1=0;
			lll z=1;
			while(z<=no)
			{	
				aans1=aans1+log10(a[z-1]);
				aans=(aans*(a[z-1])%mm)%mm;
				z=1+(i)*rr;
		//		cout<<i<<" "<<z<<" "<<aans<<endl;
				i++;
			}
			lll no=(lll)aans1;
			double dec=aans1-(double)no+0.000001;                                                  
			lll xx=0;
			for(int z=1;z<=9;z++)  // why this part is used
			{
				if(dec>=logs[z])
				{
					xx=z;		
				}
			}
	//		cout<<aans1<<" "<<no<<" "<<dec<<" "<<pow(10,dec);
	//		cout<<endl;
		//	lll xx;
//			while(aanz)
//			{
//				xx=aanz%10;
//				aanz=aanz/10;
//			}
		//	cout<<" ";
			cout<<xx<<" ";
			cout<<aans<<endl;
		}
	}
}
