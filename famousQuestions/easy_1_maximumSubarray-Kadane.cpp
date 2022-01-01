//TC: O(n)
//SC: O(1)
//Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        if(size==1) return nums[0];
        int sum=nums[0];
        int maxSum=nums[0];
        for(int i=1; i<size; i++){
            if(sum<0) sum=0;
            sum += nums[i];
            maxSum=max(sum, maxSum);
        }
        return maxSum;
    }
};