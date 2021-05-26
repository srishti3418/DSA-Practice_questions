#include<iostream>
using namespace std;

void isconnected(int **edges, int n, bool*visited, int sv){
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv)
			continue;
		else{	
			if(edges[sv][i]==1){
				if(visited[i]==true)
					continue;
				else
					isconnected(edges,n,visited,i);
		     			}
		}
				}
							}

bool isconnected(int **edges, int n){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
				}
	isconnected(edges,n,visited,0);
	for(int i=0;i<n;i++){
		if(visited[i]==false)
			return false;
			   }
	return true;
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
	bool ans=isconnected(edges,n);
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"false"<<endl;
	   }
