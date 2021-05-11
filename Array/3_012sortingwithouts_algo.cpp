#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int arr[], int n)
{
    // coode here
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            a++;
        else if(arr[i]==1)
            b++;
        else
            c++;
    }
    int i=0;
        while(a!=0){
            arr[i]=0;
            a--;
            i++;
        }
        while(b!=0){
            arr[i]=1;
            b--;
            i++;
        }
        while(c!=0){
            arr[i]=2;
            c--;
            i++;
        }
}

//Time complexity: O(n)
//Space complexity: O(1)
