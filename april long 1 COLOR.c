#include<stdio.h>
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int r,g,b,k;
        int min=1;
        int counter=1;
        scanf("%d %d %d",&r,&g,&b);
        scanf("%d",&k);
        while(counter!=k)
        {
	        if(k==1)
	        	min=1;
	        else
	        {
	        	if(r>0 && g>0 && b>0)
	        	{
	        		min=min+3;
	        		counter++;
	        	}
	        	else if(r>0 && g>0 && b<=0)
	        	{
	        		min=min+2;
	        		counter++;
	        	}
	        	else if(r>0 && b>0 && g<=0)
	        	{
	        		min=min+2;
	        		counter++;
	        	}
	        	else if(b>0 && g>0 && r<=0)
	        	{
	        		min=min+2;
	        		counter++;
	        	}
	        	else if(r>0 && g<=0 && b<=0)
	        	{
	        		min=min+1;
	        		counter++;
	        	}
	        	else if(g>0 && r<=0 && b<=0)
	        	{
	        		min=min+1;
	        		counter++;
	        	}
	        	else if(b>0 && g<=0 && r<=0)
	        	{
	        		min=min+1;
	        		counter++;
	        	}
	        	else
	        		break;

	       		r--;g--;b--;
        	}
        }
        printf("%d\n",min);
    }
}
