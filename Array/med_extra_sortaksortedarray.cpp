
#include <iostream>
#include <queue>
using namespace std;

//Brute force approach (using insertion sort)
//TC: O(n*k)
//SC: O(1)
void insertion_k_sort(int arr[], int n, int k){
  if(n==0 || n==1)
    return;
  int i=0;
  while(i<n-1){
    int j=i;
    int count=0;
    do{
      if(arr[j+1]<arr[j]){
        swap(arr[j+1],arr[j]);
        j--;
        count++;
      }
      else
        break;
    }
    while(count<k && j>=0);
    i++;
  }
  return;
}

//Most optimized solution(using min heap)
//TC: O(n*logk)
//SC: O(k)
void sortwithpq(int arr[], int n, int k){
  if(n==0 || n==1)
    return;
  int size;
  size = (n==k) ? k : k+1;
  priority_queue<int, vector<int>, greater<int> > pq(arr, arr+size);

  int index=0;
  for(int i=k+1; i<n; i++){

    arr[index++]=pq.top();
    pq.pop();
    pq.push(arr[i]);

  }
  while(!pq.empty()){
    arr[index++]=pq.top();
    pq.pop();
  }
  return;
}

int main(){
  int n, k;
  cin>>n>>k;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  //insertion_k_sort(arr, n, k);
  sortwithpq(arr, n, k);
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}