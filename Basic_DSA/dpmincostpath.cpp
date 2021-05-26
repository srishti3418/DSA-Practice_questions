#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

//brute force
int mincostpath(int **arr, int n, int m, int i, int j){
	if(i>n-1 || j>m-1)
		return INT_MAX;
	if(i==n-1 && j==m-1)
		return arr[i][j];
	int a=mincostpath(arr, n, m, i, j+1);
	int b=mincostpath(arr, n, m, i+1, j);
	int c=mincostpath(arr, n, m, i+1, j+1);
	
	return min(a,min(b,c)) + arr[i][j];
							}

//Memoization
int mincostpath_2(int **arr,int n, int m, int i, int j, int **output){
	if(i>n-1 || j>m-1)
		return INT_MAX;
	if(i==n-1 && j==m-1)
		return arr[i][j];
	if(output[i][j]!=-1)
		return output[i][j];
	int a=mincostpath_2(arr, n, m, i, j+1, output);
	int b=mincostpath_2(arr, n, m, i+1, j,output);
	int c=mincostpath_2(arr, n, m, i+1, j+1, output);
	
	int ans=min(a,min(b,c))+arr[i][j];
	output[i][j]=ans;
		
	return ans;
									}

int mincostpath_2(int **arr, int n,int m){
	int **output;
	output=new int*[n];
	for(int i=0;i<n;i++){
		output[i]=new int[m];
				}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			output[i][j]=-1;
				    }
				}
	return mincostpath_2(arr, n, m, 0, 0, output);
					}
int mincostpath_3(int **arr,int n, int m){
	int **output;
	output=new int*[n];
	for(int i=0;i<n;i++){
		output[i]=new int[m];
				}
	int i=n-1;
	for(int j=m-1;j>=0;j--){
		if(i==n-1 && j==m-1)
			output[i][j]=arr[i][j];
		else{
			output[i][j]=arr[i][j]+output[i][j+1];
		    }
				}
	int j=m-1;
	for(int i=n-2;i>=0;i--){
		output[i][j]=arr[i][j]+output[i+1][j];
				}
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			output[i][j]=min(output[i+1][j],min(output[i][j+1],output[i+1][j+1]))+arr[i][j];
					}
				}
	return output[0][0]; 			
				}
int main(){
	int **arr,n,m;
	cin>>n>>m;
	arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[m];
			    }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
				     }
			     }
	cout<<"Brute force:"<<endl<<mincostpath(arr,n,m,0,0)<<endl;
	cout<<"Memoization:"<<endl<<mincostpath_2(arr,n,m)<<endl;
	cout<<"DP:"<<endl<<mincostpath_3(arr,n,m)<<endl;
	}
