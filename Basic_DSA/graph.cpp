#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

//DFS
void print(int **edges, int n, bool *visited,int sv){
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv)
			continue;
		else{
			if(visited[i]==true)
				continue;
			else{
				print(edges,n,visited,i);
			    }
		     }
				}

							}
//BFS
void printed(int **edges, int n, bool *visit, int sv){
	unordered_map<int,bool> marked;
	queue<int> pendingnodes;
	pendingnodes.push(sv);
	marked[sv]=true;
	int i=0;
	while(!pendingnodes.empty()){
		int a=pendingnodes.front();
		pendingnodes.pop();
		if(visit[a]==false){
			cout<<a<<" ";
			visit[a]=true;
				   }
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			else{
				if(edges[i][j]==1 && (visit[i]==false || visit[j]==false)){
					if(marked[j]==true)
						continue;
					else{
						pendingnodes.push(j);
						marked[j]=true;
					    }
											   }
				}
					}
	i++;
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
		int f, s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[f][s]=1;
			     }
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
			     }
	//DFS(Depth first search)
	//print(edges, n, visited, 0);
	
	cout<<endl;
	//BFS(breadth first search)
	printed(edges,n,visit,0);
	  }
