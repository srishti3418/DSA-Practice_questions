class Solution{   
public:

    //Brute force approach
    //TC: O(n^2)
    //SC: O(1)
    /*int getPairsCount(int arr[], int n, int k) {
        // code here
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==k){
                    count++;
                }
            }
        }
        return count;
    }*/
    
    //most Optimized solution
    //TC: O(n)
    //SC: O(n)
    unordered_map<int,int> m;
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int twice_count=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            twice_count += m[k-arr[i]];
            if(k-arr[i]==arr[i])
                twice_count--;
        }
        return twice_count/2;
    }
    
    
};
