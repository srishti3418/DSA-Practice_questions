#include<iostream>
using namespace std;

int fibo_2(int n,int *ans){
	if(n<=1)
		return n;
	if(ans[n]!=-1){
		return ans[n];
			}
	int a=fibo_2(n-1,ans);
	int b=fibo_2(n-2,ans);
	ans[n]=a+b;
	return ans[n];
			}

int fibo_2(int n){
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
			     }
	return fibo_2(n,ans);
	  }
int fibo_1(int n){
	if(n<=1)
		return n;
	int a=fibo_1(n-1);
	int b=fibo_1(n-2);
	return a+b;
		 }
int fibo_3(int n){
	int *ans=new int[n+1];
	ans[0]=0;
	ans[1]=1;
	for(int i=2;i<=n;i++){
		ans[i]=ans[i-1]+ans[i-2];
				}
	return ans[n];
		}
int main(){
	int n;
	cin>>n;
	//Brut force
	cout<<"Brut force:"<<endl<<fibo_1(n)<<endl;
	//Memoization
	cout<<"Memoization:"<<endl<<fibo_2(n)<<endl;
	//dynamic programming
	cout<<"DP:"<<endl<<fibo_3(n)<<endl;
	}
