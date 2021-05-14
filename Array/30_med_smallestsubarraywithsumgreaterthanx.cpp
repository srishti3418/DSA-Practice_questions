//Most optimized solution(two-pointer approach)
//TC: O(n)
//SC: O(1)
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here  
        int curr_sum=0;
        int min_len=n+1;
        int start=0,end=0;
        while(end<n){
            while(curr_sum<=x && end<n){
                curr_sum += arr[end++];
            }
            while(curr_sum>x && start<n){
                if(end-start<min_len)
                    min_len=end-start;
                curr_sum -= arr[start++];
            }
        }
        if(min_len>n)
            return 0;
        return min_len;
    }
};
