#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //Brute force approach: O(n^3), M1
    /*int threeSumSmaller(vector<int>& nums, int target) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]<target){
                        count++;
                    }
                }
            }
        }
        return count;
    }*/
    
    //Best approach: O(n^2), M2
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0; i<nums.size()-2;i++){
            int x=twosumsmaller(nums, i+1, target-nums[i]);
            sum += x;
        }
        return sum;
    }
    
    int twosumsmaller(vector<int>& nums, int startindex,int target){
        int i=startindex;
        int j=nums.size()-1;
        int sum=0;
        while(i<j){
            if(nums[i]+nums[j]<target){
                sum += j-i;
                i++;
            }
            else{
                j--;
            }
        }
        return sum;
    }
    
    
};

int main(){
	vector<int> v;
	v.push_back(-2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	int target=2;
	Solution sol;
	cout<<sol.threeSumSmaller(v,target);
}
