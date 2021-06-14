//Most optimized solution
//Time complexity: T(n)=T(k)+T(n-k-1)+O(n) => O(nlogn):average time complexity 
//In worst case recuurence relation will be: T(n)=T(0)+T(n-1)+O(n) (when array is either in ascending order
//or descending order that is pivot itself is partition)
//Space complexity: O(1)
#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int i=low-1;
    int pivot = arr[high];
    for(int j=low; j<=high-1; j++){

        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high){
    if(low<high){

        int pivot_index = partition(arr, low, high);

        quicksort(arr, 0, pivot_index-1);
        quicksort(arr, pivot_index+1, high);

    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}