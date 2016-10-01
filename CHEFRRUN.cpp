//optimised algo
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n,a[100005];
	    cin>>n;
	    for(int i=0;i<n;i++)
	        scanf("%d",&a[i]);
	    set<int> rep;
	    set<int> nrep;
	    std::set<int>::iterator x;
	    std::set<int>::iterator y;
	    for(int i=0;i<n;i++)
	    {
	        int temp[100005]={0};
	        vector<int> vi;
	        //x=rep.find(i);
	        const bool is_in = rep.find(i) == rep.end();              //returns 1 if not found
	        const bool is_in1 = nrep.find(i) == nrep.end();
          //  cout<<is_in<<is_in1<<endl;
	        if(is_in && is_in1)
	        {
	            int j;
    	        for(j=i;;)
    	        {
    	            const bool check = rep.find(j)==rep.end();
    	            const bool check1 = nrep.find(j)==nrep.end();
    	            if(check1 && check)
                    {
                        temp[j]++;
                        if(temp[j]==2)
                            break;
                        vi.push_back(j);
                        j=(j+a[j]+1)%n;
                    }
                    else
                        break;
    	        }
    	   /*     for(vector<int>::iterator q=vi.begin();q!=vi.end();q++)
                    cout<<*q<<"-->";
                    cout<<endl<<j<<endl;*/
    	        int x=0;

    	        for(vector<int>::iterator i=vi.begin();i!=vi.end();i++)
    	        {
    	            if(*i==j)
    	                x=1;
    	            if(x==0)
    	                nrep.insert(*i);
    	            else
    	                rep.insert(*i);
                    /*for(set<int>::iterator q=rep.begin();q!=rep.end();q++)
                        cout<<*q<<"-->";
                    cout<<endl;*/
    	        }
	        }
	    }
	    cout<<rep.size()<<endl;
	}
	return 0;
}
