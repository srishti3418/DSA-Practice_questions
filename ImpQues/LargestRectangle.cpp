//Optimized solution (Two pass solution), one pass solution is yet to be done.
//TC: O(n)
//SC: O(n)
class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {
        int maxi = INT_MIN;
        int n = arr.size();
        if (n == 1)
            return arr[0];
        vector<int> nextSmall(n, -1);
        vector<int> prevSmall(n, -1);
        stack<pair<int, int>> s1, s2;

        //calculating the nextSmaller element's index for every element.
        for (int i = n - 1; i >= 0; i--)
        {

            while (!s1.empty() && s1.top().second >= arr[i])
                s1.pop();
            if (!s1.empty() && s1.top().second < arr[i])
            {
                nextSmall[i] = s1.top().first;
            }
            s1.push(make_pair(i, arr[i]));
        }

        //calculating the prevSmaller element's index for every element.
        for (int i = 0; i < n; i++)
        {

            while (!s2.empty() && s2.top().second >= arr[i])
                s2.pop();
            if (!s2.empty() && s2.top().second < arr[i])
            {
                prevSmall[i] = s2.top().first;
            }
            s2.push(make_pair(i, arr[i]));
            if (nextSmall[i] == -1)
                nextSmall[i] = n;

            int temp_area = (nextSmall[i] - prevSmall[i] - 1) * arr[i];
            maxi = max(maxi, temp_area);
        }
        return maxi;
    }
};