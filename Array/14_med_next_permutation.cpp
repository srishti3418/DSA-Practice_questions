
//Most optimized solution
//TC: O(n)
//SC: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
            return;
        int index1,index2;
        int i=n-2;
        for(;i>=0;i--){
            if(arr[i]<arr[i+1]){
                index1=i;
                break;
            }
        }
        if(i==-1){
            sort(arr.begin(),arr.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]>arr[index1]){
                index2=i;
                break;
            }
        }
        swap(arr[index1],arr[index2]);
        reverse(arr.begin()+index1+1,arr.end());
    }
};
