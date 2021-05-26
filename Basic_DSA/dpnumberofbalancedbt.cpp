#include<iostream>
#include<cmath>
using namespace std;

int numofbalancedbt(int h){
	if(h<=1)
		return 1;
	
	int mod=(int) (pow(10,9)+7);
	int x=numofbalancedbt(h-1);
	int y=numofbalancedbt(h-2);

	int temp1=(int) (((long)(x)*x)%mod);
	int temp2=(int) ((2*(long)(x)*y)%mod);
	int ans=(temp1+temp2)%mod;
	return ans;
			  }
int numofbalancedbt_2(int h,int*ans){
	if(h<=1)
		return 1;
	if(ans[h] != -1){
		return ans[h];
			}
	int mod=(int) (pow(10,9)+7);
	int x=numofbalancedbt_2(h-1,ans);
	int y=numofbalancedbt_2(h-2,ans);

	int temp1=(int) (((long)(x)*x)%mod);
	int temp2=(int) ((2*(long)(x)*y)%mod);
	int res=(temp1+temp2)%mod;
	ans[h]=res;
	return ans[h];
				}
int numofbalancedbt_2(int h){
	int *ans=new int[h+1];
	for(int i=0;i<=h;i++){
		ans[i]=-1;
				}
	return numofbalancedbt_2(h,ans);
	}
int numofbalancedbt_3(int h){
	int *ans=new int[h+1];
	ans[0]=1;
	ans[1]=1;
	int mod=(int) (pow(10,9)+7);
	for(int i=2;i<=h;i++){
		int temp1=(int) (((long)(ans[i-1])*ans[i-1])%mod);
		int temp2=(int) ((2*(long)(ans[i-1])*ans[i-2])%mod);
		ans[i]=(temp1+temp2)%mod;
				}
	return ans[h];
	}
int main(){
	int h;
	cin>>h;
	cout<<"Brut force:"<<endl<<numofbalancedbt(h)<<endl;
	cout<<"Memoization:"<<endl<<numofbalancedbt_2(h)<<endl;
	cout<<"DP:"<<endl<<numofbalancedbt_3(h)<<endl;
	  }
