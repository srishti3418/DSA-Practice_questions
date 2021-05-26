#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **edges, int n, bool *visited, int sv){
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv)
			continue;
		else{
			if(edges[sv][i]==1){
				if(visited[sv]==true)
					continue;
				else
					printDFS(edges, n, visited,i);
		     }
				}
								}
							}

void DFS(int **edges, int n){
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
			     }
	for(int i=0;i<n;i++){
		if(!visited[i])
			printDFS(edges,n,visited,i);
			     }	
				}
bool haspath(int **edges, int n, bool*visit,int sv, int ev){
	for(int i=0;i<n;i++){
		if(i==ev && edges[sv][i]==1){
			visit[i]=true;
			return true;
					}
				}
	for(int i=0; i<n;i++){
		if(edges[sv][i]==1 && (visit[i]==false || visit[sv]==false)){
			visit[i]=true;
			bool ans=haspath(edges,n,visit,i,ev);
			if(ans)
				return true;
				   					     }
				}
	return false;
						}
int main(){
	int n,e;
	cin>>n>>e;
	int **edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
			     }
	for(int i=0;i<n;i++){
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
	DFS(edges,n);
	bool *visit=new bool[n];
	for(int i=0;i<n;i++){
		visit[i]=false;
			    }
	int sv,ev;
	cin>>sv>>ev;
	bool res=haspath(edges,n,visit,sv,ev);
	if(res)
		cout<<"True"<<endl;
	else{
		cout<<"False"<<endl;
	    }
	}
