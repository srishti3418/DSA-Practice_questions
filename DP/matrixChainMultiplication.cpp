#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

int dp[100][100];

//TC: O(n^3)
//SC: O(n^2)
//Recursion and Memoization (DP approach also gives same TC)
int CalculateOpr(int arr[], int left, int right)
{
    if (left >= right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    dp[left][right] = INT_MAX;
    for (int i = left; i < right; i++)
    {
        int left_part = CalculateOpr(arr, left, i);
        int right_part = CalculateOpr(arr, i + 1, right);
        int cost = arr[left - 1] * arr[i] * arr[right];

        dp[left][right] = min(dp[left][right], left_part + right_part + cost);
    }
    return dp[left][right];
}

int MinimumMatrixOpr(int arr[], int size)
{
    int i = 1, j = size - 1;
    for (int k = 1; k <= j; k++)
    {
        for (int h = 1; h <= j; h++)
        {
            dp[k][h] = -1;
        }
    }
    return CalculateOpr(arr, i, j);
}

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << MinimumMatrixOpr(arr, n + 1) << endl;
}