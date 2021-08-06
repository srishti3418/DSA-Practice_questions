//TC: O(n1+n2)
//SC: O(n2+n1)
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> result(n1, -1);
        unordered_map<int, int> umap;
        stack<int> s;
        if (n1 == 0 || n2 == 0)
            return result;
        for (int i = 0; i < n2; i++)
        {
            int ele = nums2[i];
            while (!s.empty() && ele > s.top())
            {
                umap[s.top()] = ele;
                s.pop();
            }
            s.push(ele);
        }

        for (int i = 0; i < n1; i++)
        {
            int ele = nums1[i];
            if (umap.find(ele) != umap.end())
            {
                result[i] = umap[ele];
            }
        }
        return result;
    }
};