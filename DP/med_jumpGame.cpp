//TC: O(n)
//SC: O(1)

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        int jump = nums[0];
        int i = 1;
        for (; i < n; i++)
        {
            if (jump <= 0)
                break;
            jump--;
            jump = max(jump, nums[i]);
        }
        if (i < n)
            return false;
        return true;
    }
};