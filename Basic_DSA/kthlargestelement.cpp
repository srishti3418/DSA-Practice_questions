#include<iostream>
#include<queue>
using namespace std;

//inefficient code
/*int kthlargestelement(int *arr,int n, int k){
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
			    }
	int j=0;
	int ans;
	while(j<k){
		ans=pq.top();
		pq.pop();
		j++;
		  }
	return ans;
					}*/

//efficient code
int kthlargestelement(int *arr,int n,int k){
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0;i<k;i++){
		pq.push(arr[i]);
				}
	for(int i=k;i<n;i++){
		if(arr[i]>pq.top()){
			pq.pop();
			pq.push(arr[i]);
				   }
			}
	return pq.top();
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
	cout<<kthlargestelement(arr,n,k)<<endl;
	}
