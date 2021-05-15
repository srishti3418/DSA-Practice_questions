//Most optimized solution(two-pointer approach and sliding window approach)
//TC: O(n)
//SC: O(1)
int minSwap(int *arr, int n, int k) {
    // Complete the function
    int count = 0;
    int bad = 0;
    
    for (int i = 0; i < n; i++){
        if (arr[i] <= k)
            count++;
    }
  
    for (int i = 0; i < count; i++){
        if (arr[i] > k)
            bad++;
    }
    
    int ans = bad;
    int i = 0, j = count;
    while(j < n) {
          
        if (arr[i] > k)
            bad--;
          
        if (arr[j] > k)
            bad++;
          
        ans = min(ans, bad);
        i++;
        j++;
    
    }
    return ans;
}
