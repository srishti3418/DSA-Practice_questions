class Solution
{
public:
    //TC: O(nlogn)
    //SC: O(1)
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 1, j = 0;
        int platform_needed = 1;
        int maxi = 1;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                i++;
                platform_needed++;
            }
            else if (arr[i] > dep[j])
            {
                j++;
                platform_needed--;
            }
            maxi = max(maxi, platform_needed);
        }
        return maxi;
    }
};
