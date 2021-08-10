//TC: O(m*n)
//SC: O(m*n)
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int ans = -1;
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (q.size())
        {
            int size = q.size();
            ans++;
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int i = p.first + dir[k];
                    int j = p.second + dir[k + 1];
                    if (i < 0 || i == n || j < 0 || j == m)
                        continue;
                    if (grid[i][j] == 1)
                    {
                        q.push(make_pair(i, j));
                        grid[i][j] = 2;
                        fresh--;
                    }
                }
            }
        }
        if (fresh > 0)
            return -1;
        if (ans == -1)
            return 0;
        return ans;
    }
};