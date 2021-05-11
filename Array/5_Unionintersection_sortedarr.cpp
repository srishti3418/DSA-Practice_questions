#include <iostream>
#include <unordered_map>
using namespace std;


//For unsorted arrays: count of union and intersection elements
//Time complexity: O(m+n)
//Space complexity: O(1)
int removedup(int a[], int n, int b[], int m){
    unordered_map<int,bool> mp;
    int count=0;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end()){
            mp[a[i]]=true;
            count++;
        }
    }
    for(int i=0;i<m;i++){
        if(mp.find(b[i])==mp.end()){
            mp[b[i]]=true;
            count++;
        }
    }
    return count;
}

int countintersectionele(int a[], int n, int b[], int m){
    unordered_map<int,bool> mp;
    int count=0;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end()){
            mp[a[i]]=true;
        }
    }
    for(int i=0;i<m;i++){
        if(mp.find(b[i])!=mp.end()){
            count++;
        }
    }
    return count;
    
}

//For sorted arrays: count of union and intersection elements
//Time complexity: O(m+n)
//Space complexity: O(1)
int countunionele(int a[], int n, int b[], int m){
    int count=0;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            count++;
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            count++;
            i++;
        }
        else{
            count++;
            j++;
        }
    }
    while(i<n){
        count++;
        i++;
    }
    while(j<m){
        count++;
        j++;
    }
    return count;
}

int count_intersect_ele(int a[], int n,int b[], int m){
	int count=0;
    int i=0;
    int j=0;
    while(i<n && j<m){
    	 if(a[i]==b[j]){
            count++;
            i++;
            j++;
        }
		else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return count;	
    }

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,m;
	    cin>>n>>m;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    int b[m];
	    for(int j=0;j<m;j++){
	        cin>>b[j];
	    }
	    
	    //for unsorted array
	    cout<<"union: "<<removedup(a ,n, b, m)<<endl;
	    cout<<"intersection"<<countintersectionele(a, n, b, m)<<endl;
	    
	    //for sorted array
	    //cout<<"union"<<countunionele(a,n,b,m)<<endl;
	    //cout<<"intersection"<<count_intersect_ele(a,n,b,m)<<endl;
	    
	}
	return 0;
}
