//Recursive Solution
//TC: exponential
int minPath(vector<vector<int>> &grid, int x, int y)
{
    if (x < 0 || y < 0)
        return INT_MAX;
    if (x == 0 && y == 0)
        return grid[x][y];
    return grid[x][y] + min(minPath(grid, x - 1, y), minPath(grid, x, y - 1));
}

int Solution::minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return minPath(grid, n - 1, m - 1);
}

//Dynamic programming approach
//TC: O(n*m)
//SC: O(1)
int Solution::minPathSum(vector<vector<int>> &grid)
{
    int rows = grid.size();
    if (rows == 0)
        return 0;
    int cols = grid[0].size();
    for (int i = 1; i < cols; i++)
    {
        grid[0][i] = grid[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < rows; i++)
        grid[i][0] = grid[i - 1][0] + grid[i][0];

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
    }
    return grid[rows - 1][cols - 1];
}
