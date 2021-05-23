/*You are required to complete this method*/
//Most optimized solution
//TC: O(n*m)
//SC: O(m)
class Solution{
  public:
    int mhist(int row[], int m1) {
    
        stack<int> result;
    
        int top_val;
    
        int max_area = 0;
    
        int area = 0;
        int i = 0;
        for (i = 0; i < m1;) {
    
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);
    
            else {
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;
    
                if (!result.empty()) area = top_val * (i - result.top() - 1);
                max_area = max(area, max_area);
            }
        }
    
        while (!result.empty()) {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty()) area = top_val * (i - result.top() - 1);
    
            max_area = max(area, max_area);
        }
        return max_area;
    }
    
    int kewl(int M[MAX][MAX], int n, int m) {
        int res = mhist(M[0], m);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
    
                if (M[i][j]) M[i][j] += M[i - 1][j];
            }
            res = max(res, mhist(M[i], m));
        }
        return res;
    }
    
    
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        return kewl(M, n, m);
    }
};
