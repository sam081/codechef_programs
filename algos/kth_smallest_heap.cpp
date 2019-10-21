#include<iostream>

using namespace std;

void max_heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if(l < n && arr[l] > arr[largest])
		largest = l;
	
	if(r < n && arr[r] > arr[largest])
		largest = r;

	if(largest != i){
		swap(arr[i], arr[largest]);
		max_heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n){
	for(int i=n-1;i >= 0; i--){
		swap(arr[0], arr[i]);
		max_heapify(arr,i, 0);
	}
}


int main(){

	auto print = [](int arr[], int n){
		for(int x= 0; x<n; x++){
			cout << arr[x] << " ";
		}
		cout << endl;
	};

	while(1){
		int arr[10000],n;
		cin >> n;
		for(int i=0;i<n;i++){ cin >> arr[i]; }
		print(arr, n);
		//build heap
		for(int i = n/2 -1; i>=0; i--){
			max_heapify(arr, n, i);
		}
		print(arr,n);
		//heapsort
		heapsort(arr,n);
		print(arr,n);
	}
}
