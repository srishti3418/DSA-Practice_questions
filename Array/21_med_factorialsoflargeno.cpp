//Most optimized solution
//TC: O(n)
//SC: O(1)
class Solution {
public:

    void multiply(int n, vector<int>& number){
        int carry=0;
        for(int i=0;i<number.size();i++){
            int num = number[i]*n;
            number[i] = (num+carry)%10;
            carry = (num+carry)/10;
        }
        while(carry!=0){
            number.push_back(carry%10);
            carry /= 10;
        }
    }

    vector<int> factorial(int N){
        // code here
        vector<int> result;
        result.push_back(1);
        for(int i=2;i<=N;i++){
            multiply(i,result);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
