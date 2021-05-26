#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int minsteps(int n){
	if(n<=1)
		return 0;
	int a;
	a=minsteps(n-1);
	int b=INT_MAX;
	if(n%2==0){
		b=minsteps(n/2);
		  }
	int c=INT_MAX;
	if(n%3==0){
		c=minsteps(n/3);
		  }
	int ans=min(a,min(b,c));
	return ans+1;
		     }
int minsteps_2(int n,int *ans){
	if(n<=1)
		return 0;
	if(ans[n]!=-1){
		return ans[n]+1;
			}
	int a;
	a=minsteps_2(n-1,ans);
	int b=INT_MAX;
	if(n%2==0){
		b=minsteps_2(n/2,ans);
		  }
	int c=INT_MAX;
	if(n%3==0){
		c=minsteps_2(n/3,ans);
		  }
	int res=min(a,min(b,c));
	ans[n]=res;
	return ans[n]+1;
			}
int minsteps_2(int n){
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
			     }
	return minsteps_2(n,ans);
			}
int minsteps_3(int n){
	int *ans=new int[n+1];
	ans[1]=0;
	ans[2]=1;
	ans[3]=1;
	int a,b,c;
	for(int i=4;i<=n;i++){
		a=b=c=INT_MAX;
		a=ans[i-1];
		if(i%2==0){
			b=ans[i/2];
			  }
		if(i%3==0){
			c=ans[i/3];
			   }
		int res=min(a,min(b,c));
		ans[i]=res+1;
			       }
		return ans[n];
			}
int main(){
	int n;
	cin>>n;
	cout<<"Brut force:"<<endl<<minsteps(n)<<endl;
	cout<<"memoization:"<<endl<<minsteps_2(n)<<endl;
	cout<<"DP:"<<endl<<minsteps_3(n)<<endl;
	   }
