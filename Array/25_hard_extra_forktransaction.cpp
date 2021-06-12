//Most optimized solution
//TC: O(n*k)
//SC: O(n*k)
class Solution {
public:
    int unlimited_trans(vector<int>& prices, int n){
        int profit=0;
        for(int i=1; i<n; i++){
            if(prices[i]>prices[i-1])
                profit += prices[i]-prices[i-1];
        }
        return profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n/2)
            return unlimited_trans(prices, n);
        
        int dp[k+1][n];
        for(int i=0; i<=k; i++){
            int max_diff = INT_MIN;
            for(int j=0; j<n ;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else{
                    max_diff = max(max_diff, dp[i-1][j-1] - prices[j-1]);
                    dp[i][j] = max(dp[i][j-1], prices[j]+max_diff);
                }
            }
        }
        return dp[k][n-1];
    }
};
