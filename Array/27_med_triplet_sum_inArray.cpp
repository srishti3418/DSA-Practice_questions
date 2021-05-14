//Most optimized solution
//TC: O(n^2)
//SC: O(1)
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        int i=0;
        while(i<n-2){
            int rem=X-A[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(A[j]+A[k]<rem){
                    j++;
                }
                else if(A[j]+A[k]>rem){
                    k--;
                }
                else
                    return true;
            }
            i++;
        }
        return false;
    }

};
