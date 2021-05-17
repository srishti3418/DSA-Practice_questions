//Most optimized solution
//TC: O(m+n)
//SC: O(1)
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i=0, j=m-1;
	    int max_row_index=-1;
	    while(i<n && j>=0){
	        if(arr[i][j]==1){
	            max_row_index=i;
	            j--;
	        }
	        else if(arr[i][j]==0){
	            i++;
	        }
	    }
	    return max_row_index;
	}

};
