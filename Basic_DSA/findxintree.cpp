#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class treenode{
	public:
	T data;
	vector<treenode<T>*> children;
		treenode(T data){
			this->data=data;
				}
		};
	treenode<int>*takeinputlevelwise(){
		int rootdata;
		cin>>rootdata;
		treenode<int>*root=new treenode<int>(rootdata);
		queue<treenode<int>*> pendingnodes;
		pendingnodes.push(root);
		while(!pendingnodes.empty()){
			treenode<int>*front=pendingnodes.front();
			pendingnodes.pop();
			int childnum;
			cin>>childnum;
			for(int i=0;i<childnum;i++){
				int childdata;
				cin>>childdata;
				treenode<int>*child=new treenode<int>(childdata);
				front->children.push_back(child);
				pendingnodes.push(child);
						   }
						}
			return root;
					}
	void printlevelwise(treenode<int>*root){
		queue<treenode<int>*> pendingnodes;
		pendingnodes.push(root);
		while(!pendingnodes.empty()){
			treenode<int>*front=pendingnodes.front();
			pendingnodes.pop();
			cout<<front->data<<":";
			for(int i=0;i<front->children.size();i++){
				cout<<front->children[i]->data<<",";
				pendingnodes.push(front->children[i]);
								  }
			cout<<endl;
						}
							}
	bool findnode(treenode<int>*root,int k){
		if(root==NULL){
			return false;
				}
			if(root->data==k){
				return true;
					}
		for(int i=0;i<root->children.size();i++){
			bool ans=findnode(root->children[i],k);
			if(ans==true){
				return true;
				     }
							}
		return false;
						}
	int nodesgreaterthanx(treenode<int>*root,int k){
		int count=0;
		if(root->data>k){
			count=1;
				}
		else{
			count=0;
		    }
		for(int i=0;i<root->children.size();i++){
			count += nodesgreaterthanx(root->children[i],k);
							}
		return count;
							}
	int nodewithmaxsum(treenode<int>*root){
		int sum=0;
		int maxsum=sum;
		if(root->children.size()==0){
			sum=root->data;
			return sum;
					    }
		for(int i=0;i<root->children.size();i++){
			sum += nodewithmaxsum(root->children[i]);
							}}
int main(){
	int k;
	cin>>k;
	treenode<int>*root=takeinputlevelwise();
	//printlevelwise(root);
	if(findnode(root,k)){
		cout<<"True"<<endl;
			}
	else{
		cout<<"False"<<endl;
	    }
	
	int num=nodesgreaterthanx(root,k);
	cout<<num<<endl;
	
	}
