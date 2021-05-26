#include<iostream>
using namespace std;
#include <stack>

int main(){
	stack<int> s1;
	stack<int> s2;
	int size;
	cin>>size;
	int input;
	for(int i=0;i<size;i++){
		cin>>input;
		s1.push(input);
				}
	for(int i=0;i<size;i++){
		int ans=s1.top();
		s1.pop();
		s2.push(ans);
				}
	int arr[size];
	for(int i=0;i<size;i++){
		int ans=s2.top();
		s2.pop();
		arr[i]=ans;
		}
	for(int i=size-1;i>=0;i--){
		s1.push(arr[i]);
				}
	for(int i=0;i<size;i++){
		int ans=s1.top();
		cout<<ans<<" "; 
		s1.pop();
				}
}
