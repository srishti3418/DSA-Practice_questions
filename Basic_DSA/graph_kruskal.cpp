#include<iostream>
#include<algorithm>
using namespace std;

class MST{
	public:
	int source;
	int dest;
	int weight;
	};

bool compare(MST m, MST n){
	return (m.weight<n.weight);
			   }
int PARENT(int v, int*parent){
	if(parent[v]==v)
		return v;
	PARENT(parent[v],parent);
			      }
int main(){
	int v,e;
	cin>>v>>e;
	MST*input=new MST[e];
	MST*output=new MST[v-1];
	for(int i=0;i<e;i++){
		int fe,se,w;
		cin>>fe>>se>>w;
		input[i].source=fe;
		input[i].dest=se;
		input[i].weight=w;
			    }
	sort(input,input+e,compare);
	int*parent=new int[v];
	for(int i=0;i<v;i++){
		parent[i]=i;
			    }
	int count=0;
	int i=0;
	while(count<v-1){
		int source_par=PARENT(input[i].source,parent);
		int dest_par=PARENT(input[i].dest,parent);
		if(source_par!=dest_par){
			output[i].source=input[i].source;
			output[i].dest=input[i].dest;
			output[i].weight=input[i].weight;
			source_par=dest_par;
			i++;
			count++;
									}
		else{
			i++;
		    }
			}
	for(int i=0;i<v-1;i++){
		if(output[i].source<output[i].dest){
			cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight;
			cout<<endl;
						   }
		else{
			cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight;
		     }
			       }
		}
