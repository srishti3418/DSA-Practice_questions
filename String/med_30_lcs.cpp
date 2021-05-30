//Most optimized solution
//TC: O(n1*n2)
//SC: O(n1*n2)
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n1=s1.length();
        int n2=s2.length();
        
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};
