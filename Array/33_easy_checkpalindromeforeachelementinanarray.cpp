#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
#include<vector>
using namespace std;

bool checkpalindrome(vector<int>& v){
    int n=v.size();
    int i=0;
    int j=n-1;
    while(i<j){
        if(v[i]==v[j]){
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int PalinArray(int a[], int n)
{  //add code here.
    for(int i=0;i<n;i++){
        vector<int> v;
        while(a[i]>0){
            v.push_back(a[i]%10);
            a[i] /= 10;
        }
        if(checkpalindrome(v)==1)
            continue;
        else
            return 0;
    }
    return 1;
}
