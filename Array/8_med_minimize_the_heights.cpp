//Optimized solution
//Time complexity: O(nlogn)
//Space complexity: O(1).

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        int smallest = arr[0] + k, largest = arr[n-1]-k;
        int mini;
        int maxi;
        for(int i = 0; i < n-1; i++){
            mini = min(smallest, arr[i+1]-k);
            maxi = max(largest, arr[i]+k);
            if(mini < 0) continue;
            ans = min(ans, maxi-mini);
        }
        return ans;
    }
};
