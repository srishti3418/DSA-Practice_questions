
//TC: O(n)
//SC: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

void printdups(char s[], int n){
	unordered_map<char,int> m;

	for(int i=0;i<n;i++){
		m[s[i]]++;
	}

	for(pair<char,int> p: m){
		if(p.second>1)
			cout<<p.first<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	char s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	printdups(s,n);
}