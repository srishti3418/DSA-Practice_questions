#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

void printpair(int *arr,int n,int k){
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		int key=arr[i];
		m[key]++;
			    }
	for(int i=0;i<n;i++){
		int key=arr[i];
		if(k==0){
			int a=m[key];
			int count=((a-1)*a)/2;
			for(int j=0;j<count;j++){
				cout<<key<<" "<<key<<endl;
						}
			}
		else{
			int a=key+k;
			int b=key-k;
			int count=m[key];
			int count1=m[a];
			int count2=m[b];
			for(int l=0;l<count*count1;l++){
				cout<<min(a,key)<<" "<<max(a,key)<<endl;
							}
			for(int h=0;h<count*count2;h++){
				cout<<min(b,key)<<" "<<max(b,key)<<endl;
							}
		    }
		m.erase(key);
				}
					}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			    }
	int k;
	cin>>k;
	printpair(arr,n,k);
	}
