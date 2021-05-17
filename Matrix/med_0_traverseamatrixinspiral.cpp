//Most optimized solution
//TC: O(m*n)
//SC: O(m*n)
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int m, int n) 
    {
        // code here 
        vector<int> arr;
           int i,k=0,l=0;
           while(k<m && l<n){
               for(i=l;i<n;i++)
                    arr.push_back(matrix[k][i]);
                k++;
                for(i=k;i<m;i++)
                    arr.push_back(matrix[i][n-1]);
                n--;
                if(k<m){
                    for(i=n-1;i>=l;i--){
                        arr.push_back(matrix[m-1][i]);
                    }
                    m--;
                }
                if(l<n){
                    for(i=m-1;i>=k;i--){
                        arr.push_back(matrix[i][l]);
                    }
                    l++;
                }
           }
   return arr;
    }
};
