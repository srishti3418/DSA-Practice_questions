#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int editdistance(string s, string t){
	if(s.size()==0 || t.size()==0)
		return max(s.size(),t.size());
	if(s[0]==t[0])
		return editdistance(s.substr(1),t.substr(1));
	int a=editdistance(s.substr(1),t);
	int b=editdistance(s,t.substr(1));
	int c=editdistance(s.substr(1),t.substr(1));
	
	return 1+min(a,min(b,c));
					}
int editdistance_2(string s,string t,int **output){
	int n=s.size();	
	int m=t.size();
	if(n==0 || m==0)
		return max(n,m);
	int ans;
	if(output[n][m]!=-1)
		ans=output[n][m];
	else{
		int a=editdistance(s.substr(1),t);
		int b=editdistance(s,t.substr(1));
		int c=editdistance(s.substr(1),t.substr(1));
	
		ans=1+min(a,min(b,c));
		}
	output[n][m]=ans;
	return ans;
						}
int editdistance_2(string s, string t){
	int n=s.size();
	int m=t.size();
	int **output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i]=new int[m+1];
				}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			output[i][j]=-1;
					}
				}
	return editdistance_2(s,t,output);
					}
int editdistance_3(string s, string t){
	int n=s.size();
	int m=t.size();
	int **output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i]=new int[m+1];
				}
	int i=0;
	for(int j=0;j<=m;j++){
		output[i][j]=j;
				}
	int j=0;
	for(int i=1;i<=n;i++){
		output[i][j]=i;
			     }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[n-i]==t[m-j])
				output[i][j]=output[i-1][j-1];
			else
				output[i][j]=1+min(output[i-1][j],min(output[i][j-1],output[i-1][j-1]));
					}
				}
	return output[n][m];
				    }
int main(){
	string s;
	string t;
	cin>>s>>t;
	cout<<"Brute force:"<<endl<<editdistance(s,t)<<endl;
	cout<<"Memoization:"<<endl<<editdistance_2(s,t)<<endl;
	cout<<"DP:"<<endl<<editdistance_3(s,t)<<endl;
	  }

