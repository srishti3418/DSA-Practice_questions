#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int n1=mid-start+1;
    int n2=end-mid;

    int temp1[n1], temp2[n2];

    for(int i=0; i<n1; i++){
        temp1[i]=arr[start+i];
    }
    for(int j=0; j<n2; j++){
        temp2[j]=arr[mid+1+j];
    }

    int i=0, j=0, k=start;
    while(i<n1 && j<n2){
        if(temp1[i] <= temp2[j])
            arr[k++]=temp1[i++];
        else
            arr[k++]=temp2[j++];
    }
    while(i<n1)
        arr[k++]=temp1[i++];
    while(j<n2)
        arr[k++]=temp2[j++];
    return;
}

void mergesort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr,start, mid, end);
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}