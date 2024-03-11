#include <iostream>
using namespace std;

int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int sum = (length * (length + 1))/2;
        int arrSum = 0;
        for(int i=0; i<length; i++){
            arrSum += nums[i];
        }
        return sum - arrSum;
    }

int main() {
    cout << missingNumber([3,0,1]) <<endl;
};