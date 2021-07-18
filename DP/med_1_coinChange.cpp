//The greedy approach(sortnig the coins array and then traversing from the last of the array) won't give minimum number of coins for every test cases. That approach will give wrong ans.
//USE either recursive or dp.

//Most optimized solution
//TC: O(m*amount)
//SC: O(amount)
class Solution
{
public:
    int coinChange(vector<int> &coins, int m, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] != amount + 1)
            return dp[amount];
        else
            return -1;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int m = coins.size();
        return coinChange(coins, m, amount);
    }
};