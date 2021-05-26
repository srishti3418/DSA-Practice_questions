#include<iostream>
#include<unordered_map>
using namespace std;

int printsubset(int*arr,int n){
	unordered_map<int,int> m;
	for(int i=1;i<n;i++){
		arr[i] += arr[i-1];
				}
	int maxlen=0;
	for(int i=0;i<n;i++){
		int key=arr[i];
		if(m.count(key)==0){
			m[key]=i;
				   }
		else if(m.count(key)==1){
			if(maxlen<(i-m[key])){
				maxlen=i-m[key];
						}
					}
				}
	return maxlen;
				  }

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			     }
	int ans=printsubset(arr,n);
	cout<<ans<<endl;
	  }
