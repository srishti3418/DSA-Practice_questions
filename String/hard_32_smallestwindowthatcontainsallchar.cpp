#include<iostream>
#include<string>
#include<climits>
using namespace std;

string findSubString(string str){

	int n=str.length();
	int dist_count=0;
	bool visited[256]={false};

	for(int i=0;i<n;i++){
		if(visited[str[i]]==false){
			visited[str[i]]=true;
			dist_count++;
		}
	}

	int start=0, start_index=-1;
	int curr_str[256]={0};
	int count=0;
	int min_len=INT_MAX;
	for(int j=0;j<n;j++){

		curr_str[str[j]]++;

		if(curr_str[str[j]]==1)
			count++;

		if(count==dist_count){

			while(curr_str[str[j]]>1){
				curr_str[str[j]]--;
				start++;
			}

			int window_len=j-start+1;
			if(min_len>window_len){
				min_len=window_len;
				start_index=start;
			}
		}
	}
	return str.substr(start_index,min_len);
}

int main(){
	string str="aabcbcdbca";
	cout<<findSubString(str)<<endl;
}