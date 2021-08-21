//TC: O(n)
//SC: O(n)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
        {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for (int i = 3; i < n; i++)
        {
            dp[i] = dp[i - 2] + nums[i] > dp[i - 3] + nums[i] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
        }

        return dp[n - 1] > dp[n - 2] ? dp[n - 1] : dp[n - 2];
    }
};