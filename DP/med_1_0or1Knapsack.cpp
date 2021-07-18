#include <iostream>
#include <cmath>
using namespace std;
int dp[100][100];

//Recursion and Memoization
//TC: O(N*W)
//SC: O(N*W)
int maximum_profit(int profit[], int wt[], int j, int weight)
{
    if (j == -1 || weight == 0)
        return 0;
    if (dp[j][weight] != -1)
        return dp[j][weight];
    int result;
    if (wt[j - 1] > weight)
        result = maximum_profit(profit, wt, j - 1, weight);
    else
        result = max(maximum_profit(profit, wt, j - 1, weight), profit[j - 1] +
                                                                    maximum_profit(profit, wt, j - 1, weight - wt[j - 1]));
    return dp[j][weight] = result;
}

//Dynamic Programming (This one is optimized)
//TC: O(N*W)
//SC: O(N*W)
int maximum_profit2(int profit[], int wt[], int weight, int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - wt[i - 1]]);
        }
    }
    return dp[n][weight];
}

int main()
{
    int n;
    cin >> n;
    int wt[n];
    int profit[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    int weight;
    cin >> weight;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << maximum_profit(profit, wt, n, weight) << endl;
    cout << maximum_profit2(profit, wt, weight, n) << endl;
}