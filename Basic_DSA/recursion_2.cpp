#include<iostream>
#include<cmath>
using namespace std;

int multiplication(int m,int n){
	if(n==0){
		return 0;
		}
	int smallans=multiplication(m,n-1);
	return m+smallans;
				}
int numofzeros(int t){
	if(t<=9){
		if(t==0){
			return 1;
			}
		else{
			return 0;
		     }
		}
	int last=t%10;
	int count=0;
	if(last==0){
		count=1;
		   }
	return count+numofzeros(t/10);	
		}
float geometricsum(int t){
	if(t==0){
		return 1;
		}
	return geometricsum(t-1)+1/pow(2,t);
			}
int sumofdigits(int n){
	if(n<=9){
		return n;
		}
	return n%10+sumofdigits(n/10);
			}
int main(){
	//int m,n;
	//cin>>m>>n;
	//int ans=multiplication(m,n);
	//cout<<ans<<endl;
	int t;
	cin>>t;
	//int ans=numofzeros(t);
	//cout<<ans<<endl;
	//float ans=geometricsum(t);
	//cout<<ans<<endl;
	int ans=sumofdigits(t);
	cout<<ans<<endl;
	}
