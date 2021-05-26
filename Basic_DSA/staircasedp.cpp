#include<iostream>
using namespace std;

int staircase_1(int n){
	if(n<=2)
		return n;
	if(n==3)
		return 4;
	int a=staircase_1(n-1);
	int b=staircase_1(n-2);
	int c=staircase_1(n-3);
	return a+b+c;
			}
int staircase_2(int n,int *ans){
	if(n<=2)
		return n;
	if(n==3)
		return 4;
	if(ans[n]!=-1)
		return ans[n];
	int a=staircase_2(n-1,ans);
	int b=staircase_2(n-2,ans);
	int c=staircase_2(n-3,ans);
	ans[n]=a+b+c;
	return ans[n];
				}
int staircase_2(int n){
	int *ans=new int[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=-1;
				}
	return staircase_2(n,ans);
			}

int staircase_3(int n){
	long*ans=new long[n+1];
	ans[0]=0;
	ans[1]=1;
	ans[2]=2;
	for(int i=3;i<=n;i++){
		long x=ans[i-1];
		long y=ans[i-2];
		long z=ans[i-3];
		if(i==3)
			ans[i]=4;
		else
			ans[i]=x+y+z;
				}
	return ans[n];
			}

int main(){
	int n;
	cin>>n;
	cout<<"Brut force:"<<endl<<staircase_1(n)<<endl;
	cout<<"Memoization:"<<endl<<staircase_2(n)<<endl;
	cout<<"DP:"<<endl<<staircase_3(n)<<endl;
	}
