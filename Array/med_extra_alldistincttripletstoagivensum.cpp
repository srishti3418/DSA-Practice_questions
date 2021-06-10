#include <algorithm>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    for(int i=0;i<n-2;i++){
        int k=n-1;
        int j=i+1;
        while(j<k){
            if(arr[i]+arr[j]+arr[k]<K){
                j++;
            }
            else if(arr[i]+arr[j]+arr[k]>K){
                k--;
            }
            else{
                int x=arr[j];
                int y=arr[k];
                result.push_back({arr[i],arr[j],arr[k]});
                while(j<k && arr[j]==x)
                    j++;
                while(j<k && arr[k]==y)
                    k--;
            }
        }
        while(arr[i]==arr[i+1])
            i++;
    }
    return result;
}
