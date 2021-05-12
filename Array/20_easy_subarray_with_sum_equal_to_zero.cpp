class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    
    //Most optimized solution
    //TC: O(n)
    //SC: O(n)
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int,bool> m;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum==0 || m[sum]==true)
                return true;
            m[sum]=true;
        }
        return false;
    }
};
