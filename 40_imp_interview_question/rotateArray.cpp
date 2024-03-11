#include <iostream>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    vector<int> ans(len, 0);
    
    for (int i = 0; i < len; i++) {
        int index = (i + k);
        if(index <= len-1){
            ans[index] = nums[i];
        }  
        else{
            ans[index%len]=nums[i];
        }
        
    }
    for(int i=0; i<len; i++){
        nums[i]=ans[i];
    }
}

int main(){
    rotate([1,2,3,4,5,6,7], 3);
}

