// A frog is situated at (0,0). It needs to reach (n,0). It should travel along the x axis only.  It can either jump 1,2 or 3 units at a time. In how many distinct ways can the frog reach its destination?

// Sample Input: 3
// Output: 4
int countWays(vector<int> &dp, int n)
{
    dp[0] = 1;
    if (n == 0)
        return dp[n];
    dp[1] = 1;
    if (n == 1)
        return dp[n];
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main()
{
    //std::cout << "Hello World!\n";
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    cout << countWays(dp, n) << endl;
}