vector<int> findCommonElements(vector<vector<int>> &mat)
{
    //    Write your code here
    int M = mat.size();
    int N = mat[0].size();
    vector<int> res;
    unordered_map<int, int> mp;

    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
 
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
           
            if(mp.find(mat[i][j])!=mp.end()){
                if (mp[mat[i][j]] == i)
                {
                    mp[mat[i][j]] = i + 1;
                }
            }
        }
    }
    
    for(pair<int,int> p: mp){
        if(p.second==M)
            res.push_back(p.first);
    }
    return res;
}
