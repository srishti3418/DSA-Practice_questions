//Most optimized solution (Moore voting algorithm)
//TC: O(n)
//SC: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1;
        int m2;
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++){
            if(m1==nums[i])
                c1++;
            else if(m2==nums[i])
                c2++;
            else if(c1==0){
                m1=nums[i];
                c1++;
            }
            else if(c2==0){
                m2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> result;
        c1=0;
        c2=0;
        for(int n:nums){
            if(n==m1)
                c1++;
            if(n==m2)
                c2++;
        }
        int n=nums.size();
        if(c1>n/3)
            result.push_back(m1);
        if(c2>n/3)
            result.push_back(m2);
        
        return result; 
    }
};
