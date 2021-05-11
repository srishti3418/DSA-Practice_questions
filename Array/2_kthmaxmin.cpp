// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
int kthSmallest_2(int arr[], int l, int r, int k);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
        cout<<kthSmallest_2(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends

// Time complexity of this method: Average time complexity is O(n) while worst time complexity will be O(n^2) and hence not preferred.
// Algorithm is quick select algorithm and it involves partition algorithm too.
//Space complexity:O(1)

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//partition algorithm for finding pivot
int partition(int arr[],int l,int r){
    int x=arr[r],i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
     
        }
    }
    i++;
    swap(&arr[i],&arr[r]);
    return i;
}


int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    if(k>0 && k<=r-l+1){
        int pos=partition(arr,l,r);
        if(pos-l==k-1){
            return arr[pos];
        }
        if(pos-l>k-1){
            return kthSmallest(arr,l,pos-1,k);
        }
            return kthSmallest(arr,pos+1,r,k-pos+l-1);

    }
    
    // If k is more than number of elements in array 
    return INT_MAX; 
}

//2nd method and preferred, sorting algorithm is used.
// Time complexity: O(nlogn)
//Space complexity: O(n)
int kthSmallest_2(int arr[], int l, int r, int k) {
    //code here
   int n=r-l+1;
   sort(arr,arr+n);
   return arr[k-1];
   }
