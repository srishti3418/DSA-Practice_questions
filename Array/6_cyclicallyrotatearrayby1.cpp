#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int j=0;j<n;j++){
	        cin>>arr[j];
	    }
	    int temp=arr[n-1];
	    for(int j=n-1;j>0;j--){
	        arr[j]=arr[j-1];
	    }
	    arr[0]=temp;
	    for(int j=0;j<n;j++){
	        cout<<arr[j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}

//Algorithm: Reversal algorithm
//Time complexity: O(n)
//Space complexity: O(1)
