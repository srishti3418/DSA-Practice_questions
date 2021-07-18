class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    int dp[2][n+1];
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0 || j==0)
		                dp[i%2][j]=0;
		            else if(str[i-1]==str[j-1] && i!=j)
		                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
		            else
		                dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
		        }
		    }
		    return dp[n][n];
		}

};

//Most optimized solution (dynamic programming)
//TC: O(n^2)
//SC: O(n^2)
