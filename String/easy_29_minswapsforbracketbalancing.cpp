
//Most optimized solution
//TC: O(n)
//SC:O(1)
class Solution{   
public:

    int minimumNumberOfSwaps(string S){
        // code here 
        int swap=0,imbalance=0;
        int leftcount=0,rightcount=0;
        int n=S.length();
        
        for(int i=0;i<n;i++){
            if(S[i]=='['){
                leftcount++;
                if(imbalance>0){
                    swap += imbalance;
                    imbalance--;
                }
            }
            else{
                rightcount++;
                imbalance=rightcount-leftcount;
            }
        }
        return swap;
    }
};
