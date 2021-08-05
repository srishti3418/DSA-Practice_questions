//TC: O(n)
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        vector<int> ans;
        ans = digits;
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
                ans[i] = 0;
            else
            {
                ans[i]++;
                return ans;
            }
        }
        ans.push_back(0);
        ans[0] = 1;
        return ans;
    }
};