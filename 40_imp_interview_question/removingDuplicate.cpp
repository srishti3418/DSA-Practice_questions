#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len==0 || len==1)
            return len;
        int slowPointer=0;
        for(int fastPointer=0; fastPointer<len; fastPointer++){
            if(nums[slowPointer]!=nums[fastPointer]){
                slowPointer++;
                nums[slowPointer]=nums[fastPointer];
            }
        }
        return slowPointer+1;
    }

int main(){
    int arr=[1,1,2,3,4,4,4];
    cout<<removeDuplicates(arr);
}