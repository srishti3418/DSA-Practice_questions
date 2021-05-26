#include<iostream>
#include<vector>
using namespace std;

vector<int>*connectedcomp(int **edges,int n,bool*visited,int sv, vector<int>*comp){
	comp->push_back(sv);
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv)
			continue;
		else{
			if(edges[i][sv]==1){
				if(visited[i]==true)
					continue;
				else
					connectedcomp(edges,n,visited,i,comp);
					   }
		   }
				}
	return comp;
											}

void connectedcomp(int **edges, int n){
	bool*visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
			    }
	for(int i=0;i<n;i++){	
		vector<int>*comp=new vector<int>[n];
		if(!visited[i]){
			vector<int>*output=connectedcomp(edges,n,visited,i,comp);
			for(int i=0;i<output->size();i++){
				cout<<output->at(i)<<" ";
							}	
			cout<<endl;
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
	connectedcomp(edges,n);
	  }
