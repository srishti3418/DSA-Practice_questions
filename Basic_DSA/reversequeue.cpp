#include<iostream>
using namespace std;
#include <queue>

void reversequeue(queue<int> &q,int size){
	int arr[size];
	for(int h=0;h<size;h++){
		int ans=q.front();
		q.pop();
		arr[h]=ans;
				}
	int i=0;
	int j=size-1;
	while(i<j){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
		   }
	for(int i=0;i<size;i++){
		q.push(arr[i]);
		cout<<q.front()<<" ";
		q.pop();
				}
	}

int main(){
	queue<int> q;
	int size;
	cin>>size;
	int input;
	for(int i=0;i<size;i++){
		cin>>input;
		q.push(input);
				}
	reversequeue(q,size);
	}
