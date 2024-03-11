#include <iostream>
using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0 && n==0)
            return;
        if(m==0 && n!=0){
            nums1=nums2;
            return;
        }
        if(m!=0 && n==0){
            return;
        }
        int i=0, j=0, k=0;
        vector<int> temp(m+n);
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                temp[k]=nums1[i];
                i++;
                k++;
            }
            else{
                temp[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<m){
            temp[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n){
            temp[k]=nums2[j];
            j++;
            k++;
        }
        for(int l=0;l<m+n;l++){
            nums1[l]=temp[l];
        }
        return;
    }


int main(){
    int nums1=[1,2,3,0,0,0];
    int nums2=[2,5,6];
    merge(nums1, 3, nums2, 3);
}