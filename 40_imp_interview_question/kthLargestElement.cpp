class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        sort(nums.begin(), nums.end());
        return nums[len-k];
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int i=0; i<len; i++){
        //     pq.push(nums[i]);
        //     if(pq.size()>k)
        //         pq.pop();
        // }
        // return pq.top();
    }
};