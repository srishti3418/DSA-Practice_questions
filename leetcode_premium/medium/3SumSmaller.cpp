class Solution {
public:
    //Brute force approach: O(n^3), M1
    /*int threeSumSmaller(vector<int>& nums, int target) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]<target){
                        count++;
                    }
                }
            }
        }
        return count;
    }*/
    //better approach than brute force: O(n^2logn), M2(binary search)
    /*int threeSumSmaller(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int sum=0;
        if(nums.size()<3)
            return 0;
        for(int i=0;i<nums.size()-2;i++){
            sum += twosumsmaller(nums, i+1, target-nums[i]);
        }
        return sum;
    }
    
    int twosumsmaller(vector<int>& nums,int startindex, int target){
        int sum=0;
        for(int i=startindex;i<nums.size()-1;i++){
            int j=binarysearch(nums, i, target-nums[i]);
            sum += j-i;
            }
        return sum;
        }
    int binarysearch(vector<int>& nums, int startindex, int target){
        int j=nums.size()-1;
        int i=startindex;
        while(i<j){
            int mid=(i+j+1)/2;
            if(nums[mid]<target)
                i=mid;
            else
                j=mid-1;
                  }
        return i;
    }*/
    
    
    
    //Best approach: O(n^2), M3
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=0;
        if(nums.size()<3)
            return 0;
        for(int i=0; i<nums.size()-2;i++){
            int x=twosumsmaller(nums, i+1, target-nums[i]);
            sum += x;
        }
        return sum;
    }
    
    int twosumsmaller(vector<int>& nums, int startindex,int target){
        int i=startindex;
        int j=nums.size()-1;
        int sum=0;
        while(i<j){
            if(nums[i]+nums[j]<target){
                sum += j-i;
                i++;
            }
            else{
                j--;
            }
        }
        return sum;
    }
    
};