//TC: O(logn)
//SC: O(1)
class Solution
{
public:
    int findnonDuplicate(vector<int> &nums, int n)
    {
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return nums[low];
    }

    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return findnonDuplicate(nums, n);
    }
};