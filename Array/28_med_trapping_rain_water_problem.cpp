class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
    //Brute force approach
    //TC: O(n^2)
    //SC: O(1)
    /*int trappingWater(int arr[], int n){
        // Code here
        int water=0;
        
        for(int i=0;i<n;i++){
            int left_max=arr[i];
            int right_max=arr[i];
            
            for(int j=i-1;j>=0;j--){
                if(left_max<arr[j])
                    left_max=arr[j];
            }
            for(int j=i+1;j<n;j++){
                if(right_max<arr[j])
                    right_max=arr[j];
            }
            
            water += min(left_max,right_max)-arr[i];
            
        }
        return water;
    }*/
    
    //Better approach (using extra space)
    //TC: O(n)
    //SC: O(n)
    /*int trappingWater(int arr[], int n){
        // Code here
        int water=0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++){
            left[i]=max(arr[i],left[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            right[i]=max(arr[i],right[i+1]);
        }
        
        for(int i=0;i<n;i++){
            water += min(left[i],right[i])-arr[i];
        }
        return water;
    }*/
    
    
    //Most optimized solution (Using two pointer approach)
    //TC: O(n)
    //SC: O(1)
    int trappingWater(int arr[], int n){
        // Code here
        int left=0;
        int right=n-1;
        int ans=0;
        int left_max=arr[0];
        int right_max=arr[n-1];
        
        while(left<right){
            if(left_max<=right_max){
                ans += left_max-arr[left++];
            }
            else if(right_max<left_max){
                ans += right_max-arr[right--];
            }
            
            left_max=max(left_max,arr[left]);
            right_max=max(right_max,arr[right]);
        }
        
        return ans;
        
    }
};
