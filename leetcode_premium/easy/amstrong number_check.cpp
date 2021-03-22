class Solution {
public:
    bool isArmstrong(int n) {
        int sum=0;
        int k=0;
        int p=n;
        int z=n;
        while(n>0){
            k++;
            n=n/10;
        }
        while(p>0){
            int x=p%10;
            sum = sum+pow(x,k);
            p=p/10;
        }
        if(sum==z)
            return true;
        else
            return false;
    }
};