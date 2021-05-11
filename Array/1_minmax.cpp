#include<iostream>
using namespace std;

class min_max{
    public:
        int maximum;
        int minimum;
                    };
//1st method and naive approach(linear search)
//Worst time complexity: O(n)
//space complexity: O(1)
//Number of comparison in worst case(when in descending order): 1+2(n-2)
min_max findminmax1(int arr[],int n){
    min_max pair;
    if(n==1){
            pair.minimum=arr[0];
            pair.maximum=arr[0];
            return pair;
    }
    else{
        if(arr[0]<arr[1]){
                pair.minimum=arr[0];
                pair.maximum=arr[1];
        }
        else{
            pair.minimum=arr[1];
            pair.maximum=arr[0];
        }
        for(int i=2;i<n;i++){
            if(arr[i]<pair.minimum)
                pair.minimum=arr[i];
            else if(arr[i]>pair.maximum)
                pair.maximum=arr[i];
        }
        return pair;
    }
    }

//2nd method and better approach(tournament method/divide and conquer method)
//Worst time complexity: O(n)
//space complexity: O(1)
//Number of comparison in worst case(when in descending order): T(n)=2T(n/2)+2 that is T(n)=3n/2-2 when n is power of 2
min_max findminmax2(int arr[], int left, int right){
    min_max pair,mml,mmr;
    if(left==right){
        pair.minimum=arr[left];
        pair.maximum=arr[right];
        return pair;
    }
    else{
        if(right==left+1){
            if(arr[left]<arr[right]){
                    pair.minimum=arr[left];
                    pair.maximum=arr[right];
            }
            else{
                pair.minimum=arr[right];
                pair.maximum=arr[left];
            }
            return pair;
        }
        int mid=(left+right)/2;
        mml=findminmax2(arr,left,mid);
        mmr=findminmax2(arr,mid+1,right);
        if(mml.minimum<mmr.minimum){
            pair.minimum=mml.minimum;
        }
        else{
            pair.minimum=mmr.minimum;
        }
         if(mml.maximum<mmr.maximum){
            pair.maximum=mmr.maximum;
        }
        else{
            pair.maximum=mml.maximum;
        }
    return pair;
    }
    }

//3rd method and best approach(compare in pairs)
//Worst time complexity: O(n)
//space complexity: O(1)
//Number of comparison in worst case(when in descending order): T(n)=2T(n/2)+2 that is T(n)=3n/2-2 when n is power of 2
//This method has same number of comparisons at that of 2nd but this is preferred. 
min_max findminmax3(int arr[],int n){
    min_max pair;
    int i;
    if(n%2==0){
        if(arr[0]<arr[1]){
            pair.minimum=arr[0];
            pair.maximum=arr[1];
        }
        else{
            pair.minimum=arr[1];
            pair.maximum=arr[0]; 
        }
        i=2;
    }
    else{
         pair.minimum=arr[0];
         pair.maximum=arr[0];
         i=1;
    }
    while(i<n){
        if(arr[i]<arr[i+1]){
            if(arr[i]<pair.minimum){
                pair.minimum=arr[i];
            }
            if(arr[i+1]>pair.maximum){
                pair.maximum=arr[i+1];
            }
        }
        else{
            if(arr[i+1]<pair.minimum)
                pair.minimum=arr[i+1];
            if(arr[i]>pair.maximum)
                pair.maximum=arr[i];
        }
        i+=2;
    }
    return pair;
    }


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    min_max pair=findminmax1(arr,n);
    cout<<"maximum"<<":"<<pair.maximum<<endl<<"minimum"<<":"<<pair.minimum<<endl;
    
     pair=findminmax2(arr,0,n-1);
     cout<<"maximum"<<":"<<pair.maximum<<endl<<"minimum"<<":"<<pair.minimum<<endl;

     pair=findminmax3(arr,n);
     cout<<"maximum"<<":"<<pair.maximum<<endl<<"minimum"<<":"<<pair.minimum<<endl;

    }
