//Better approach (important, dynamic programming)
//TC: O(m*n)
//SC: O(m*n)
/*class Solution {
public:
    int minDistance(string s, string t) {
        int m=s.length();
        int n=t.length();
        
        
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else 
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
        return dp[m][n];
    }
};*/

//Most optimized approach (Dynamic programming but use of % decreases space)
//TC: O(m*n)
//SC: O(m)

class Solution {
public:
    int minDistance(string s, string t) {
        int m=s.length();
        int n=t.length();
        int dp[2][m+1];
        
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0)
                    dp[i%2][j]=i;
                else if(s[j-1]==t[i-1])
                    dp[i%2][j]=dp[(i-1)%2][j-1];
                else 
                    dp[i%2][j]=min(min(dp[(i-1)%2][j],dp[i%2][j-1]),dp[(i-1)%2][j-1])+1;
            }
        }
        return dp[n%2][m];
    }
};

