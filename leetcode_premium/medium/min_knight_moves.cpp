//Most optimized solution: DFS with memoization
//TC: O(x*y)
//SC: O(x*y)

class Solution {
public:
    map < pair <int, int>, int > dp;
    int solve(int x, int y){
      if(x + y == 0) return 0;
      if (x + y == 2) return 2;
      pair <int, int> temp({x, y});
      if(dp.count(temp)) return dp[temp];
      return dp[temp] = min(solve(abs(x - 1), abs(y - 2)), solve(abs(x - 2), abs(y - 1))) + 1;
   }
    int minKnightMoves(int x, int y) {
        return solve(abs(x), abs(y));
    }
};
