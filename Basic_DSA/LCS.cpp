#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int LCS(string s, string t){
	if(s.size()==0 || t.size()==0)
		return 0;
	if(s[0]==t[0]){
		return 1+LCS(s.substr(1),t.substr(1));
			}
	int a=LCS(s.substr(1),t);
	int b=LCS(s,t.substr(1));
	int c=LCS(s.substr(1),t.substr(1));

	return max(a,max(b,c));
			     }
int LCS_2(string s, string t, int **output){
	int m=s.size();
	int n=t.size();
	if(m==0 || n==0)
		return 0;
	if(output[m][n]!=-1){
		return output[m][n];
			     }
	int ans;
	if(s[0]==t[0]){
		ans=1+LCS_2(s.substr(1),t.substr(1),output);
			}
	else{
		int a=LCS_2(s.substr(1),t,output);
		int b=LCS_2(s,t.substr(1),output);
		int c=LCS_2(s.substr(1),t.substr(1),output);
		ans=max(a,max(b,c));
	     }
	output[m][n]=ans;
	return ans;
						}
int LCS_2(string s, string t){
	int m=s.size();
	int n=t.size();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
				}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
					}
				}
	return LCS_2(s,t,output);
				}
int LCS_3(string s, string t){
	int m=s.size();
	int n=t.size();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
			     }
	int i=0;
	for(int j=0;j<=n;j++){
		output[i][j]=0;
			}
	int j=0;
	for(int i=1;i<=m;i++){
		output[i][j]=0;
				}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[m-i]==t[n-j]){
				output[i][j]=output[i-1][j-1]+1;
					   }
			else{
				output[i][j]=max(output[i-1][j],max(output[i][j-1],output[i-1][j-1]));
			     }
					}
				}
	return output[m][n];
				}
int main(){
	string s,t;
	cin>>s>>t;
	cout<<"Brute force:"<<endl<<LCS(s,t)<<endl;
	cout<<"Memoization:"<<endl<<LCS_2(s,t)<<endl;
	cout<<"DP:"<<endl<<LCS_3(s,t)<<endl;
	  }
