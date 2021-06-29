//TC: O(n)
//SC: O(n)
class Solution {
public:
    unordered_set<int> s;
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int size=1;
        for(int i=0; i<n; i++){
            
            if(s.find(nums[i]-1)==s.end()){
                int cnt=0;
                for(int j=nums[i]; s.find(j)!=s.end(); j++)
                    cnt++;
                size=max(size, cnt);
            }
        }
       return size;
    }
};
