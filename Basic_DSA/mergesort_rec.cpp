#include<iostream>
using namespace std;

void merge(int input[],int si,int ei){
	int mid=(si+ei)/2;
	int i=si;
	int j=mid+1;
	int k=0;
	int output[ei+1];
	while(i<=mid && j<=ei){
		if(input[i]<=input[j]){
			output[k]=input[i];
			k++;
			i++;
					}
		else{
			output[k]=input[j];
			k++;
			j++;
		    }
			}
	while(i<=mid){
		output[k]=input[i];
		i++;
		k++;
			}
	while(j<=ei){
		output[k]=input[j];
		j++;
		k++;
			}
	int m=0;
	for(int h=si;h<=ei;h++){
		input[h]=output[m];
		m++;
				}
	return;
		}
void mergesort(int input[],int si,int ei){
	if(si>=ei){
		return;
		   }
	int mid=(si+ei)/2;
	mergesort(input,0,mid);
	mergesort(input,mid+1,ei);
	merge(input,si,ei);
	return;				}

int main(){
	int size;
	cin>>size;
	int input[size];
	for(int i=0;i<size;i++){
		cin>>input[i];
				}
	mergesort(input,0,size-1);
	for(int i=0;i<size;i++){
		cout<<input[i]<<" ";
				}
	cout<<endl;
	}
