#include<iostream>
using namespace std;

int partition(int input[],int si,int ei){
		int count=0;
		int first=input[si];
		for(int i=si+1;i<=ei;i++){
			if(input[i]<=first){
				count++;
					  }
					}
		int i=si;
		int j=ei;
		int z=si+count;
		int temp=input[z];
		input[z]=first;
		input[si]=temp;
		while(i<=z && j>=z){
			while(input[i]<=input[z]){
				i++;
						}
			while(input[j]>input[z]){
				j--;
						   }
			if(i<z && j>z){
				swap(input[i],input[j]);
				i++;
				j--;
			    }
					}
		return z;
						}

void quicksort(int input[],int si,int ei){
	if(si>=ei){
		return;
		}
	int c=partition(input,si,ei);
	quicksort(input,si,c-1);
	quicksort(input,c+1,ei);
					}

int main(){
	int size;
	cin>>size;
	int input[size];
	for(int i=0;i<size;i++){
		cin>>input[i];
				}
	quicksort(input,0,size-1);
	for(int i=0;i<size;i++){
		cout<<input[i]<<" ";
				}
		cout<<endl;
	}
