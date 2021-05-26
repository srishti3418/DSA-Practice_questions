#include<iostream>
using namespace std;

int binarysearch(int input[],int si,int ei,int k){
	if(si>ei){
		return -1;
		}
	int mid=(si+ei)/2;
	if(k<input[mid]){
		return binarysearch(input,si,mid-1,k);
			}
	if(k==input[mid]){
		return mid;
			}
	if(k>input[mid]){
		return binarysearch(input,mid+1,ei,k);
			}
						}

int main(){
	int size;
	cin>>size;
	int input[size];
	for(int i=0;i<size;i++){
		cin>>input[i];
				}
	int k;
	cin>>k;
	int ans=binarysearch(input,0,size-1,k);
	cout<<ans<<endl;
	}
