class Solution
{
public:
    //Brute force solution
    //TC: O(n! * n)
    //SC: O(n)
    /*void recurr(vector<vector<int>> &ans, vector<int> &freq, vector<int> &nums, vector<int> &ds){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                if(!freq[i]){
                    freq[i]=1;
                    ds.push_back(nums[i]);
                    recurr(ans, freq, nums, ds);
                    freq[i]=0;
                    ds.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        recurr(ans, freq, nums, ds);
        return ans;
    }*/

    //Optimized solution
    //TC: O(N!*N)
    //SC: O(n) {but very less spaces are required as compare to previous solution}
    void recurr(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        else
        {
            for (int i = index; i < nums.size(); i++)
            {
                swap(nums[index], nums[i]);
                recurr(index + 1, nums, ans);
                swap(nums[index], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurr(0, nums, ans);
        return ans;
    }
};