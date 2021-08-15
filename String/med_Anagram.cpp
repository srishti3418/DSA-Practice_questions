//TC: O(n*m*logm) where n is the size of string_list and m is the max of the string present inside string_list
//SC: O(n*m)
class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        int n = string_list.size();
        for (int i = 0; i < n; ++i)
        {
            string tmp = string_list[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(string_list[i]);
        }
        for (auto itr : mp)
        {
            int n = itr.second.size();
            //cout << n << endl;
            vector<string> temp(itr.second);
            ans.push_back(temp);
        }
        return ans;
    }
};