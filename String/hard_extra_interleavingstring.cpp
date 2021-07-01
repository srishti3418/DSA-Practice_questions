//OPtimized solution
//TC: O(m*n)
//SC: O(m*n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m= s1.size(),n=s2.size(), s=s3.size();
        if(m+n != s) return false;
            
        vector <vector<bool>>  dp(m+1 , vector<bool> (n+1, 0));

        
        for (int i=0;i<=m;i++){
            for (int j=0;j<=n;j++){
                 if (i==0 && j==0) dp[i][j]=true;
                 else if (i==0){
                     if(s2[j-1]==s3[j-1])
                         dp[i][j]=dp[i][j-1];
                 }
                 else if (j==0) {
                     if(s1[i-1]==s3[i-1]) 
                         dp[i][j]=dp[i-1][j];
                 }

                 else if (s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1]) dp[i][j]=dp[i-1][j];
                 else if (s1[i-1]!=s3[i+j-1] && s2[j-1]==s3[i+j-1]) dp[i][j]=dp[i][j-1];
                 else if (s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]) dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        
        return dp[m][n];
    }
};
