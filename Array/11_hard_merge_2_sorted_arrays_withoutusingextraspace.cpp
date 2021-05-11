//User function template for C++
//Only solution(Most optimized) 
//TC: O((m+n)log(m+n))
//SC: O(1)
class Solution{
public:

    
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i=n-1;
	    int j=0;
	    for(;i>=0 && j<m; i--,j++){
	        if(arr1[i]>=arr2[j]){
	            swap(arr1[i],arr2[j]);
	        }
	        else
	            break;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};
