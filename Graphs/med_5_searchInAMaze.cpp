//TC: O(4^(n^2))
//SC: O(n^2)
class Solution{
    public:
    void printAllPath(int i, int j, vector<vector<int>> &m, int n, vector<vector<int>> &visited, vector<string> &ans, string s){
        
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        if(m[i][j]==0 || visited[i][j]) return;
        
        visited[i][j]=1;
        if(i+1<n) printAllPath(i+1, j, m, n, visited, ans, s+"D");
        if(j-1>=0) printAllPath(i, j-1, m, n, visited, ans, s+"L");
        if(j+1<n) printAllPath(i, j+1, m, n, visited, ans, s+"R");
        if(i-1>=0) printAllPath(i-1, j, m, n, visited, ans, s+"U");
        visited[i][j]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int> > visited(n, vector<int> (n, 0));
        ans.clear();
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
        
        if(m[0][0]!=0){
            printAllPath(0, 0, m, n, visited, ans, "");
        }
        return ans;
    }
};
