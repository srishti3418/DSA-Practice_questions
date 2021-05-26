#include<iostream>
#include<queue>
using namespace std;

void ksmallestnumber(int *arr, int n, int k){
	priority_queue<int> pq;
	for(int i=0; i<k; i++){
		pq.push(arr[i]);
				}
	for(int i=k;i<n;i++){
		int max=pq.top();
		if(arr[i]<max){
			pq.pop();
			pq.push(arr[i]);
				}
			     }
	int j=0;
	while(!pq.empty()){
		arr[j]=pq.top();
		pq.pop();
		j++;
			   }
					}
void klargestnumber(int *arr, int n, int k){
	priority_queue<int,vector<int>, greater<int> > pq;
	for(int i=0; i<k; i++){
		pq.push(arr[i]);
				}
	for(int i=k;i<n;i++){
		int min=pq.top();
		if(arr[i]>min){
			pq.pop();
			pq.push(arr[i]);
				}
			     }
	int j=0;
	while(!pq.empty()){
		arr[j]=pq.top();
		pq.pop();
		j++;
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
	//ksmallestnumber(arr, n, k);	
	klargestnumber(arr, n, k);
	for(int i=0;i<k;i++){
		cout<<arr[i]<<endl;
			    }
	}
