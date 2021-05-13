//Most optimized solution
//TC: O(nlogn)
//TC: O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void fill(int arr[], int n, int neg, int pos){
	if(neg % 2==1){
		for(int i=1;i<neg; i += 2){
			swap(arr[i],arr[i+neg]);
		}
	}
	else{
		for(int i=1;i<=neg; i += 2){
			swap(arr[i],arr[i+neg-1]);
		}
	}
}

void fill2(int arr[], int n, int neg, int pos){
	if(pos % 2==1){
		for(int i=1;i<pos; i += 2){
			swap(arr[i],arr[i+pos]);
		}
	}
	else{
		for(int i=1;i<=pos; i += 2){
			swap(arr[i],arr[i+pos-1]);
		}
	}
}

void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int neg=0, pos=0;
	for(int i=0;i<n;i++){
		if(arr[i]<0)
			neg++;
		else
			pos++;
	}
	sort(arr,arr+n);

	if(neg<=pos){
		fill(arr,n,neg,pos);
	}
	else{
		reverse(arr,arr+n);
		fill2(arr,n,neg,pos);
	}

	print(arr,n);
}
