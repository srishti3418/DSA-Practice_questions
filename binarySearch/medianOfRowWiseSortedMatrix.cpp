//Most optimized solution
//TC: O(32*r*logc)
//SC: O(1)
class Solution{   
public:

    int countElements(vector<vector<int>> &matrix, int i, int mid){
        int l=0, h=matrix[i].size()-1;
        while(l<=h){
            int md=(l+h)/2;
            if(matrix[i][md]<=mid) l=md+1;
            else h=md-1;
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int n, int m){
        // code here  
        int low=1;
        int high=2000;
       
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0; i<n; i++){
                cnt += countElements(matrix, i, mid);
            }
            if(cnt<=(m*n)/2) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
