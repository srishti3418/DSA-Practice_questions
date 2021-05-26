#include<iostream>
using namespace std;

bool checkmaxheap(int *arr,int n){
	for(int i=0;i<n;i++){
		if(((2*i+1)<n) && (arr[i]<arr[2*i+1]))
			return false;
		if(((2*i+2)<n) && (arr[i]<arr[2*i+2]))
			return false;
			   }
	return true;
				}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			    }
	bool ans=checkmaxheap(arr,n);
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	}
