#include<iostream>
using namespace std;

void heapsort(int *arr,int n){
	for(int i=1;i<n;i++){
		int CI=i;
		 while(CI>0){
                                        int parentI=(CI-1)/2;
                                        if(arr[CI]<arr[parentI]){
                                                swap(arr[CI],arr[parentI]);
                                                                        }
                                        else{
                                                break;
                                             }
                                CI=parentI;
					}
				}
	int size=n;
	while(size>1){
		swap(arr[0],arr[size-1]);
		size--;
		int PI=0;
                int CI1=2*PI+1;
                int CI2=2*PI+2;
                while(CI2<size){
                        int CI;
                        if(arr[CI1]>arr[CI2])
                                CI=CI2;
                        else
                                CI=CI1;
                        if(arr[PI]>arr[CI])
                                swap(arr[PI],arr[CI]);
                        else
                                break;
                        PI=CI;
                        CI1=2*PI+1;
                        CI2=2*PI+2;
                                }
			}
		}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			    }
	heapsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
				}
	cout<<endl;
	}
