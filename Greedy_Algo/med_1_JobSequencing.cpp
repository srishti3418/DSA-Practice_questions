//TC: O(nlogn)+O(n^2) ~ O(n^2)
//SC: O(n)
class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comp);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }
        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
        {
            slot[i] = -1;
        }

        int profit = 0, countJobs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    profit += arr[i].profit;
                    countJobs++;
                    break;
                }
            }
        }
        vector<int> result;
        result.push_back(countJobs);
        result.push_back(profit);
        return result;
    }
};
