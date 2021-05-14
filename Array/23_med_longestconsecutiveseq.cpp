class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    
    //Most optimized solutiom using hashing (set)
    //TC: O(n)
    //SC: O(n)
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int ans=0;
      unordered_set<int> s;
      for(int i=0;i<N;i++){
          s.insert(arr[i]);
      }
      for(int i=0;i<N;i++){
          if(s.find(arr[i]-1)==s.end()){
              int j=arr[i];
              while(s.find(j)!=s.end())
                j++;
              ans=max(ans,j-arr[i]);
          }
      }
      return ans;
    }
};
