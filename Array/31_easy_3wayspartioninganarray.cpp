//Most optimized solution
//TC: O(n)
//SC: O(1)
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        int n=array.size();
        int left=0;
        int right=n-1;
        int i=0;
        while(i<=right){
            if(array[i]<a){
                swap(array[i],array[left]);
                left++;
            }
            else if(array[i]>b){
                swap(array[i],array[right]);
                right--;
                i--;
            }
            i++;
        }
        
    }
};
