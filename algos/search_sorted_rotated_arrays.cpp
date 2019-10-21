#include<stdio.h>
#include<iostream>

using namespace std;

int find_pivot(int arr[],int l, int r, int n){
	if (l > r) return -1;
	int mid = (l+r)/2;

	if(mid == 0 && arr[mid] > arr[mid+1]) return 0;
	else if(arr[mid] > arr[mid+1]) return mid;
	else if(arr[mid] < arr[mid-1]) return mid-1;
	
	if (arr[l] < arr[mid])
		return find_pivot(arr, l, mid-1, n);

	return find_pivot(arr, mid+1, r, n);
}

int binarySearch(int arr[], int l, int r, int x){
	if(r < l) return -1;
	int mid = (l+r)/2;
	if(arr[mid] == x) return mid;
	else if (arr[mid] > x)
		return binarySearch(arr, l, mid-1, x);
	else  
		return binarySearch(arr, mid+1, r, x);
}

int search(int arr[],int x, int n){
	int pivot = find_pivot(arr, 0, n, n);
	
	if(pivot == -1) return binarySearch(arr, 0, n, x);

	if( arr[pivot] == x) return pivot;
	if(x <= arr[n-1] && x >= arr[pivot+1])
		return binarySearch(arr, pivot+1, n, x);
	else
		return binarySearch(arr, 0, pivot-1, x);
}

int main(){
	int n;
	cin >> n;
	int arr[1000];
	for(int i=0; i < n; i++){
		cin >>arr[i];
	}
		
	while(1){
		int x;	
		cin >> x;
		if( x== -1) break;
		cout << search(arr, x, n) << endl;
	
	}
	return 0;
}
