//Most optimized solution
//TC: O(n)
//SC:O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> m;
        m[0]=1;
        int count=0;
        int sum=0;
        for(int i:nums){
            sum += i;
            count += m[sum-k];
            m[sum]++;
            }
        return count;
    }
};
