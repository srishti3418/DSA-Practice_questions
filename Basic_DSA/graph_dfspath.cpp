#include<iostream>
#include<vector>
using namespace std;

vector<int>*DFS_path(int **edges,int n,bool*visited,int sv,int ev){
	if(sv==ev){
		vector<int>*path=new vector<int>();
		path->push_back(sv);
		return path;
		  }
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(edges[sv][i]==1 && !visited[i]){
				vector<int>*smallpath=DFS_path(edges,n,visited,i,ev);
				if(smallpath!=NULL){
					smallpath->push_back(sv);
					return smallpath;
						   }
						}
			}
	return NULL;
								}
vector<int>*DFS_path(int **edges,int n){
	bool*visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
			     }
	int sv,ev;
	cin>>sv>>ev;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			 return DFS_path(edges,n,visited,sv,ev);
				}
			     }	
						}
int main(){
	int n,e;
	cin>>n>>e;
	int **edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
				    }
				}
	for(int i=0;i<e;i++){	
		int fe,se;
		cin>>fe>>se;
		edges[fe][se]=1;
		edges[se][fe]=1;
			     }
	vector<int>*ans=DFS_path(edges,n);
	if(ans!=NULL){
		for(int i=0;i<ans->size();i++){
			cout<<ans->at(i)<<" ";
					}
		      }
	else{
		cout<<" ";
	     }
	cout<<endl;
	}
