//Most optimized solution
//TC: O(m)+O(logn)
//SC: O(1)
class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][n-1]==target)
                return true;
            else if(matrix[i][n-1]<target)
                continue;
            else{
                int ans=binary_search(matrix[i].begin(),matrix[i].end(),target);
                if(ans>0)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};
