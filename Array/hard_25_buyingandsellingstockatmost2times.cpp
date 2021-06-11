#include <iostream>
#include <cmath>
using namespace std;

//Brute force approach
//Time complexity: O(n^2)
//Space complexity: O(1)
/*int calculaterightprofit(int arr[], int start, int end){

    int max_diff = arr[end] - arr[end-1];
    int max_val = arr[end];
    for(int i = end-1; i >= start; i--){
        if(max_val - arr[i] > max_diff)
            max_diff = max_val - arr[i];
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    return max_diff;
}

int calculateleftprofit(int arr[], int start, int end){

    int max_diff = arr[start+1] - arr[start];
    int min_val = arr[start];
    for(int i = start+1; i <= end; i++){
        if(arr[i] - min_val > max_diff)
            max_diff = arr[i] - min_val;
        if(arr[i] < min_val)
            min_val = arr[i];
    }
    return max_diff;
}

int calculateprofit(int arr[], int n){
    
    int profit=0;
    for(int i=1; i<n-1; i++){
        int leftprofit = calculateleftprofit(arr, 0, i);
        int rightprofit = calculaterightprofit(arr, i+1, n-1);
        profit = max(profit, leftprofit + rightprofit);
    }

    return profit;
}*/

//Optimized solution
//Time complexity: O(n)
//Space complexity: O(n)
int calculateprofit(int arr[], int n){

    int *profit = new int[n];
    for(int i = 0; i < n ; i++){
        profit[i] = 0;
    }

    int max_val = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > max_val)
            max_val = arr[i];
        profit[i] = max(profit[i+1], max_val - arr[i]);
    }

    int min_val = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min_val)
            min_val = arr[i];
        profit[i] = max(profit[i-1], profit[i] + arr[i] - min_val);
    }

    int result = profit[n-1];

    delete [] profit;

    return result;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ;i<n; i++){
        cin>>arr[i];
    }

    cout<<calculateprofit(arr,n)<<endl;

}