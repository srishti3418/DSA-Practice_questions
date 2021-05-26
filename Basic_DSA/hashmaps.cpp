#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

vector<int> removeduplicates(int*a,int n){
	vector<int> output;
	unordered_map<int,bool> ourmap;
	for(int i=0;i<n;i++){
		if(ourmap.count(a[i])>0)
			continue;
		ourmap[a[i]]=true;
		output.push_back(a[i]);
			     }
	return output;
					}
int maxfrequency(int*a,int n){
	unordered_map<int,int> ourmap;
	for(int i=0;i<n;i++){
		if(ourmap.count(a[i])==0)
			ourmap[a[i]]=1;
		else
			ourmap[a[i]]++;
				 }
	int max=INT_MIN;
	int ans;
	for(int i=0;i<ourmap.size();i++){
		if(ourmap[a[i]]>max){
			max=ourmap[a[i]];
			ans=a[i];
				    }
					}
	return ans;
				}
void printintersection(int*a,int*b,int n,int m){
	sort(a,a+n);
	sort(b,b+m);
	int i=0;
	int j=0;
	while(i<n && j<m){
		if(a[i]==b[j]){
			cout<<a[i]<<endl;
			i++;
			j++;
			      }
		else if(a[i]>b[j]){
			j++;
				}
		else{
			i++;
		    }
			}
						}

int main(){
	/*unordered_map<string,int> ourmap;
	pair<string,int> p("abc",1);
	ourmap.insert(p);
	cout<<ourmap.size()<<endl;
	cout<<ourmap["abc"]<<endl;
	ourmap["def"]=2;
	cout<<ourmap.size()<<endl;
	cout<<ourmap.at("def")<<endl;
	if(ourmap.count("abc")>0)
		cout<<"abc is present"<<endl;
	if(ourmap.count("def")>0)
		cout<<"def is present"<<endl;
	if(ourmap.count("efy")>0)
		cout<<"efy is present"<<endl;
	else
		cout<<"efy is not present"<<endl;
	ourmap.erase("abc");
	cout<<ourmap.size()<<endl;
	ourmap.erase("def");
	cout<<ourmap.size()<<endl;
	int a[]={1,1,3,3,5,2,7,7,6,9,0};
	vector<int> output=removeduplicates(a,11);
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
				}
	cout<<endl;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
				}
	cout<<maxfrequency(arr,n)<<endl;*/
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
			     }
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
			    }
	printintersection(a,b,n,m);
	}
