#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

void extractunique(char *arr){
	int len=strlen(arr);
	unordered_map<int,int> ourmap;
	for(int i=0;i<len;i++){
		if(ourmap.count(arr[i])==0){
			ourmap[arr[i]]=1;
			cout<<arr[i];
					    }
		else
			ourmap[arr[i]]++;
			     }
			}

int main(){
	char arr[100];
	cin>>arr;
	extractunique(arr);
	cout<<endl;
	}
