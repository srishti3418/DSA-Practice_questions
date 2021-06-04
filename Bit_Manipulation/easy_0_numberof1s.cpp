class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int count=0;
        while(N>0){
            int rem=N%2;
            if(rem==1)
                count++;
            N = N/2;
        }
        return count;
    }
};

//TC: O(logn)
//SC: O(1)