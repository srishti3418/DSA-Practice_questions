//Most optimized solution
//TC: O(n)
//SC: O(1)
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long minval=arr[0];
	    long long maxval=arr[0];
	    
	    long long maxprod=arr[0];
	    
	    for(int i=1;i<n;i++){
	        if(arr[i]<0)
	            swap(minval,maxval);
	        
	        maxval=max((long long) arr[i],maxval*arr[i]);
	        minval=min((long long) arr[i],minval*arr[i]);
	        
	        maxprod=max(maxprod,maxval);
	    }
	    return maxprod;
	}
};
