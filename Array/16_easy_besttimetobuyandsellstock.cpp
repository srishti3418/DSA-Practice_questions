class Solution {
public:
    //Brute force approach
    //TC: O(n^2)
    //SC: O(1)
   /* int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int profit=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                    int x = arr[j]-arr[i];
                    if(x>profit)
                        profit=x;
            }
        }
            return profit;
        
    }*/
    
    //Most optimized one
    //TC: O(n)
    //SC: O(1)
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int profit=0;
        int minprice=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<minprice)
                minprice=arr[i];
            else if(arr[i]-minprice>profit)
                profit=arr[i]-minprice;
        }
            return profit;
        
    }
};
