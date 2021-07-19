//Most optimized solution
//TC: O(n^2)
//SC: O(n^2)
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> rows(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                rows[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(rows);
        }
        return result;
    }
};