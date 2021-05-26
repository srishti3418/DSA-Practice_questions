#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> longestconsecutiveseries(int*arr,int n){
	unordered_map<int,int> ourmap;
	vector<int> output;
	sort(arr,arr+n);
	int startI=0;
	int maxlen=1;
	int i=0;
	while(i<n){
		if(i==n-1){
			startI=i;
			ourmap.insert(startI,maxlen);
			  }
		else if (arr[i+1]-arr[i]==1){
			i++;
			maxlen++;
					     }
		else{
			ourmap.insert(startI,maxlen);
			i++;
			startI=i;	
			maxlen=1;
		     }
		 }
	int Max=INT_MIN;
	int SI;
	unordered_map<int,int>::iterator it=ourmap.begin();
	while(it!=ourmap.end()){
		if(it->second>Max){
			Max=it->second;
			SI=it->first;
				}
		it++;
				}
	for(int i=SI;i<SI+Max;i++){
		output.push_back(arr[i]);
				   }
	return output;
	}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			    }
	vector<int> output=longestconsecutiveseries(arr,n);
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
					}
	cout<<endl;
	}
