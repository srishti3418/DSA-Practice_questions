class Solution {
public:
    
    //Brute force approach (sorting)
    //Time complexity: O(nlogn)
    //Space complexity: O(1)
    /*int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int x;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                 x= nums[i];
                  break;
            }
        }
        return x;
    }*/
    
    
    //Better approach (using hashmap)
    //Time complexity: O(n)
    //Space complexity: O(n)
   /* unordered_map<int,int> ourmap;
    
    int findDuplicate(vector<int>& nums) {
        int x;
        for(int i=1;i<nums.size();i++){
            ourmap[nums[i]]=0;
        }
        for(int i=0;i<nums.size();i++){
                ourmap[nums[i]]++;
                if(ourmap[nums[i]]>1){
                    x =nums[i];
                    break;
                }
        }
        return x;
    }*/
    
    
   //Most optimized solution (Floyd cycle method)
   //TC: O(n)
   //SC: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
    
};
