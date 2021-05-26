#include<iostream>
using namespace std;

int power(int x,int n){
	if(n==0){
		return 1;
		}
	int res=power(x,n-1);
	return x*res;
			}
int sumofdigits(int arr[],int n){
	if(n==0){
		return 0;
		}
	
		return arr[0]+sumofdigits(arr+1,n-1);
				}
bool findx(int arr[],int n,int x){
	if(n==0){
		return false;
		}
	bool smallans=findx(arr+1,n-1,x);
	if(smallans){
		return true;
		     }
	else{
		if(arr[0]==x)
			return true;
		else
			return false;
	    }
				}
int findindexfromfirst(int arr[],int n,int x){
	if(n==0){
		return -1;
		}
	if(arr[0]==x){
		return 0;
			}
	int res=findindexfromfirst(arr+1,n-1,x);
	if(res!=-1){
		return res+1;
			}
	
		return res;
	    
					}
int findindexfromlast(int arr[],int n,int x){
		if(n==0){
			return -1;
			}
		if(arr[n-1]==x){
			return n-1;
				}
		int ans=findindexfromlast(arr+(n-2),n-1,x);
		if(ans!=-1){
			return ans+1;
			    }
		return ans;
						}
void findallindices(int arr[],int n,int output,int t,int x,int &k,int currentindex){
	if(currentindex==n){
		return;
		}
	if(arr[currentindex]==x){
		output[k]=currentindex;
		k++;
		     }
	findallindices(arr+1,n-1,output,t,x,k,currentindex+1);
		}
int allindices(int arr[],int n,int output,int t,int x){
	int k;
	int currentindex;
	findallindices(arr,n,output,t,x,0,0);
	return k;
						}				
int main(){
	//int x,n;
	//cin>>x>>n;
	//int ans1=power(x,n);
	//cout<<x<<"^"<<n<<"="<<ans1<<endl;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			     }
	//int ans=sumofdigits(arr,n);
	//cout<<ans<<endl;
	int x;
	cin>>x;
	/*if(findx(arr,n,x)){
		cout<<"True"<<endl;
			}
	else{
		cout<<"False"<<endl;
	   }*/
	//int ans=findindexfromlast(arr,n,x);
	//cout<<ans<<endl;
	int t=n;
	int output[t];
	int res=allindices(arr,n,output,t,x);
	for(int i=0;i<res;i++){
		cout<<output[i]<<" ";
				}
	cout<<endl;
	}
