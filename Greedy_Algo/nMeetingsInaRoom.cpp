//TC: O(nlogn)
//SC: O(n)
class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
    {
        if (a.first.second != b.first.second)
            return a.first.second < b.first.second;
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<pair<int, int>, int>> result;
        for (int i = 0; i < n; i++)
        {
            result.push_back(make_pair(make_pair(start[i], end[i]), i + 1));
        }
        sort(result.begin(), result.end(), comp);
        int last = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {

            if (result[i].first.first > last)
            {
                last = result[i].first.second;
                count++;
            }
        }
        return count;
    }
};
