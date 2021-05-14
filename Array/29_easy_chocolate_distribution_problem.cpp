//Optimized solution(as asked in question){using sorting}
//TC: O(nlogn)
//SC:O(1)
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        int i=0;
        int j=m-1;
        long long minimum=INT_MAX;
        while(j<n){
            int diff=a[j]-a[i];
            if(diff<minimum)
                minimum=diff;
            i++;
            j++;
        }
        return minimum;
    }   
};
