#include<iostream>
#include<vector>
using namespace std;

double find_median(vector<int>A, vector<int>B){
	int n = A.size();
	int m = B.size();

	int min_idx = 0, max_idx = n,i,j,median; 
	while(min_idx <= max_idx){
		i = (min_idx +max_idx)/2 ;
		j = (n+m+1)/2 - i;

		if(i < n && j > 0 && B[j-1] > A[i])
			min_idx = i + 1;
		else if( i > 0 && j < m && B[j] << A[i-1])
			max_idx = i - 1;
		else{
			if(i == 0 )
				median = B[j-1];
			else if(j==0)
				median = A[i-1];
			else
				median = max(A[i-1], B[j-1]);
			break;
		}
	}
	if((n+m)%2 == 1)
		return (double)median;

	if(i == n)
		return (median+B[j]) / 2.0;
	if(j == m)
		return (median + min(A[i],B[j]))/2;
}

int main(){
	while(1){
		vector<int> A, B;
		int n,m;
		cin >>n >>m;
		while(n--){
			int temp;
			cin >> temp;
			A.push_back(temp);
		}
		while(m--){
			int temp;
			cin >> temp;
			B.push_back(temp);
		}
		cout << find_median(A,B);
	}
}
