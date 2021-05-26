#include<iostream>
#include<queue>
using namespace std;

bool GoalTest(char edges[][13], int i, int x[], int y[]){
	/*for(int i=0;i<9;i++){
			for(int j=0;j<13;j++){
				cout<<edges[i][j];
			}
			cout<<endl;
		}*/
	cout<<i<<":"<<x[i]<<" "<<y[i]<<endl;
	if(edges[x[i]][y[i]]=='*')
		return true;
	else
		return false;
						}

int MovGen(char edges[][13], bool *visited){
	
	int x[118];
	for(int j=1;j<=118;j++){
		x[j]=-1;
	}
	int y[118];
	for(int j=1;j<=118;j++){
		y[j]=-1;
	}
	x[1]=0;
	y[1]=0;
	queue<int> q;
	q.push(1);
	int i=1;
	while(!GoalTest(edges, i, x, y)){
		if((x[i]+1) >=0 && (x[i]+1) <9 && y[i]>=0 && y[i]<13){
			if(edges[x[i]+1][y[i]]==' '){
				if(visited[i]==false){
					int k=i;
					while(x[k]!=-1){
						k++;
					}
					if(k!=i)
						k--;
					x[k+1]=x[i]+1;
					y[k+1]=y[i];
					if(edges[x[i]+1][y[i]]=='*'){
						continue;
					}
					edges[x[i]+1][y[i]]=0;
					q.push(k+1);
						     }
						   }
								 }
		if((x[i]-1) >=0 && (x[i]-1) <9 && y[i]>=0 && y[i]<13){
			if(edges[x[i]-1][y[i]]==' '){
				if(visited[i]==false){
					int k=i;
					while(x[k]!=-1){
						k++;
					}
					if(k!=i)
						k--;
					x[k+1]=x[i]-1;
					y[k+1]=y[i];
					if(edges[x[i]-1][y[i]]=='*'){
						continue;
					}
					edges[x[i]-1][y[i]]=0;
					q.push(k+1);
						     }
						   }
								 }
		if((x[i]) >=0 && (x[i]) <9 && (y[i]+1) >=0 && (y[i]+1) <13){
			if(edges[x[i]][y[i]+1]==' '){
				if(visited[i]==false){
					int k=i;
					while(x[k]!=-1){
						k++;
					}
					if(k!=i)
						k--;
					x[k+1]=x[i];
					y[k+1]=y[i]+1;
					if(edges[x[i]][y[i]+1]=='*'){
						return k+1;
					}
					edges[x[i]][y[i]+1]=0;
					q.push(k+1);
						     }
						   }
								 }
		if(x[i] >=0 && x[i] <9 && (y[i]-1) >=0 && (y[i]-1) <13){
			if(edges[x[i]][y[i]-1]==' '){
				if(visited[i]==false){
					int k=i;
					while(x[k]!=-1){
						k++;
					}
					if(k!=i)
						k--;
					x[k+1]=x[i];
					y[k+1]=y[i]-1;
					if(edges[x[i]][y[i]-1]=='*'){
						continue;
					}
					edges[x[i]][y[i]-1]=0;
					q.push(k+1);
						     }
						   }
								 }
		visited[i]=true;
		edges[x[i]][y[i]]=0;						 
		q.pop();
		i++;

											}
													}

int main(){
	int option;
	cin>>option;

	//File handling
	char edges[9][13] = { {' ','-','-','+','-','-','+','-','-','+','-','-','+'},  
									   {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|' },   
									   {'+', ' ', ' ', '+', ' ', ' ', '+',' ', ' ', '+', ' ', ' ', '+'},   
									   {'|', ' ', ' ', ' ', ' ', ' ', '|',' ', ' ', ' ', ' ', ' ', '|'},   
									   {'+','-','-','+','-','-','+',' ',' ','+','-','-','+'},   
									   {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},    
									   {'+',' ',' ','+',' ',' ','+','-','-','+',' ',' ','+'},    
									   {'|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','*'},    
									   {'+','-','-','+','-','-','+','-','-','+','-','-','+'} };    

	if(option==0){
		bool *visited=new bool[117];
		for(int i=1; i<=117; i++){
			visited[i]=false;
					}
		cout<<MovGen(edges, visited)<<endl;
		/*for(int i=0;i<9;i++){
			for(int j=0;j<13;j++){
				cout<<edges[i][j];
			}
			cout<<endl;
		}*/
			}
	}
