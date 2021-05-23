//Most optimized solution
//TC: O(NlogN): for min heapify for each insertion
//SC: O(N) for building heap

int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
  //Your code here
    priority_queue<int> pq;
        for(int i = 0;i<n;i++)
        {
            for(int j= 0;j<n;j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();

}
