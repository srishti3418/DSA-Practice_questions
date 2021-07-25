//TC: O(n!)
//SC: O(n)
class Solution
{
public:
    /*bool isSafe(int col, int row, vector<string> &board, int n){
        int dupcol=col;
        int duprow=row;
        
        while(col>=0 && row>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
        
        col=dupcol;
        row=duprow;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        col=dupcol;
        row=duprow;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    
    void solveNQueens(int col, int n, vector<string> &board, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(col, i, board, n)){
                board[i][col]='Q';
                solveNQueens(col+1, n, board, ans);
                board[i][col]='.';
            }
        }
    }*/

    void solveNQueens(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            //This if will take O(1) time wjile the previous issafe would take O(3n) time. //This is much more optimized.
            if (leftRow[i] == 0 && upperDiag[n - 1 + col - i] == 0 && lowerDiag[i + col] == 0)
            {
                board[i][col] = 'Q';
                leftRow[i] = 1;
                upperDiag[n - 1 + col - i] = 1;
                lowerDiag[i + col] = 1;
                solveNQueens(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);
                board[i][col] = '.';
                leftRow[i] = 0;
                upperDiag[n - 1 + col - i] = 0;
                lowerDiag[i + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        solveNQueens(0, n, board, ans, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};