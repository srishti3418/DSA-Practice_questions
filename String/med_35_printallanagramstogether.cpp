//Most optimized solution
//TC: O(N*|S|log|S|), where S is the length of the largest word in the string
//SCL O(N*|S|)
vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    vector<vector<string>> output;
    unordered_map<string,vector<string>> mp;
    int n=string_list.size();
    
    for(int i=0;i<n;i++){
        string s=string_list[i];
        sort(s.begin(),s.end());
        mp[s].push_back(string_list[i]);
    }
    
    for(auto it=mp.begin();it!=mp.end();it++){
        output.push_back(it->second);
    }
    return output;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
