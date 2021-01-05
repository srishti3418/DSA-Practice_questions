#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//1st method (two pointer approach)
//Time complexity: O(n)
//Space complexity: O(1)
void rearrange(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]<0 && arr[j]<0)
            i++;
        else if(arr[i]>0 && arr[j]<0){
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
        else if(arr[i]<0 && arr[j]>0){
            i++;
            j--;
        }
        else
            j--;
    }
}

//2nd method(partition process of quicksort)
//Time complexity: O(n)
//Space complexity: O(1)
void  rearrange_2(int arr[], int n){
	int j=0;
	for(int i=0; i<n; i++){
			if(arr[i]<0){
				if(i!=j)
					swap(&arr[i], &arr[j]);
				j++;
			}
	}
	}

int main() 
{ 
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
     cin>>arr[i];
 }
 rearrange(arr,n);
 for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
 }
 
} 
