//TC: O(n)
//SC: O(n)
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        if (n == 1)
            return res;
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            s.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[i] >= s.top())
                s.pop();
            if (s.empty())
                res[i] = -1;
            else
                res[i] = s.top();
            s.push(nums[i]);
        }
        return res;
    }
};