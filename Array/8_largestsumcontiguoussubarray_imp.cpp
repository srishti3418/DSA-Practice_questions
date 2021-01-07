// { Driver Code Starts
#include<iostream>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    //Brute force approach 
    //Time complexity: O(n^2)
    //Space complexity: O(1)
    /*int max=arr[0];
    for(int i=0;i<n;i++){
        int sum=arr[i];
        if(sum>max)
            max=sum;
        for(int j=i+1;j<n;j++){
            sum=sum+arr[j];
            if(sum>max){
            max=sum;
                        }
        }
    }
    return max;*/
    
    //Optimised solution(Kadane's algorithm)
    //Time Complexity: O(n)
    //Space complexity: O(1)
    int max=arr[0];
    int sum=arr[0];
    for(int i=1;i<n;i++){
        if(sum<0)
            sum=0;
        sum=sum+arr[i];
        if(sum>max)
            max=sum;
    }
    return max;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends