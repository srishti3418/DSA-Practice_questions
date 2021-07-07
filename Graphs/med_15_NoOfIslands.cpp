//TC: O(m*n)
//TC: O(m*n)
class Solution
{
    public:
    //Function to find the number of islands.
    bool isValid(int x, int y, vector<vector<bool>> &visited, vector<vector<char>>& grid, int row, int col){
        return (x>=0 && x<row && y>=0 && y<col && !visited[x][y] && grid[x][y]=='1');
    }
    
    void DFS(int x, int y, vector<vector<bool>> &visited, vector<vector<char>>& grid, int row, int col){
        
        int dx[]={-1, 0, 1, 0, 1, -1, -1, 1};
        int dy[]={0, -1, 0, 1, 1, 1, -1, -1};
        
        visited[x][y]=true;
        for(int k=0; k<8; k++){
            if(isValid(x+dx[k], y+dy[k], visited, grid, row, col))
                DFS(x+dx[k], y+dy[k], visited, grid, row, col);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        int count=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    DFS(i, j, visited, grid, row, col);
                    count++;
                }
            }
        }
        return count;
    }
};