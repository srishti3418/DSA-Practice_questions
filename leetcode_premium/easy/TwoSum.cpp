class Solution {
public:
    //Brute force approach, M1
    //TC: O(n^2)
    //SC:O(1)
    /*vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
                }
        }
        return v;
    }*/
    
    //OPtimized code using hashmap, M2
    //TC: O(n)
    //SC:O(n)
     vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
         if(nums.size()<2){
             v.push_back(NULL);
             return v;
         }
        unordered_map<int,int> ourmap;
        for(int i=0;i<nums.size();i++){
            ourmap[nums[i]]=i;
        }
         for(int i=0;i<nums.size();i++){
             int complement=target-nums[i];
             if(ourmap.find(complement)!=ourmap.end()){
                 if(i!=ourmap[complement]){
                     v.push_back(i);
                     v.push_back(ourmap[complement]);
                     return v;
                 }
             }
         }
        return v;
    }
};
