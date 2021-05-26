#include<iostream>
#include<cmath>
using namespace std;

int knapsack(int *weight, int *value, int n, int maxweight){
	if(n==0 || maxweight==0)
		return 0;
	if(weight[0]>maxweight)
		return knapsack(weight+1, value+1, n-1, maxweight);
	int x=knapsack(weight+1, value+1, n-1, maxweight-weight[0])+value[0];
	int y=knapsack(weight+1, value+1, n-1, maxweight);
	
	return max(x,y);
								}
int knapsack_2(int *weight, int *value, int n, int maxweight, int **output){
	if(n==0 || maxweight==0)
		return 0;
	if(output[n][maxweight]!=-1)
		return output[n][maxweight];
	int ans;
	if(weight[0]>maxweight)
		ans=knapsack(weight+1,value+1,n-1,maxweight);
	else{
		int x=knapsack(weight+1,value+1,n-1,maxweight-weight[0])+value[0];
		int y=knapsack(weight+1,value+1,n-1,maxweight);
	        ans=max(x,y);
	    }
	return ans;
										}
int knapsack_2(int *weight, int *value, int n, int maxweight){
	int**output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i]=new int[maxweight+1];
			      }
	for(int i=0;i<=n;i++){
		for(int j=0;j<=maxweight;j++){
			output[i][j]=-1;
						}
				}
	return knapsack_2(weight,value,n,maxweight,output);
								}
int knapsack_3(int *weight, int *value, int n, int maxweight){
	int **output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output=new int[maxweight+1];
				}
	int i=0;
	for(int j=0;j<=maxweight;j++){
		output[i][j]=0;
					}
	int j=0;
	for(int i=1;i<=n;i++){
		output[i][j]=0;
				}
	}
int main(){
	int n;
	cin>>n;
	int weight[n];
	for(int i=0;i<n;i++){
		cin>>weight[i];
			     }
	int value[n];
	for(int i=0;i<n;i++){
		cin>>value[i];
			    }
	int maxweight;
	cin>>maxweight;
	cout<<"Brute force:"<<endl<<knapsack(weight,value,n,maxweight)<<endl;
	cout<<"Memoization:"<<endl<<knapsack_2(weight,value,n,maxweight)<<endl;
	cout<<"DP:"<<endl<<knapsack_3(weight,value,n,maxweight)<<endl;
	}
