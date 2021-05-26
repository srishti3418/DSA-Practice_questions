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
		cout<<"Enter the root data:"<<endl;
		cin>>rootdata;
		treenode<int>*root=new treenode<int>(rootdata);
		queue<treenode<int>*> pendingnodes;
		pendingnodes.push(root);
		while(!pendingnodes.empty()){
			treenode<int>*front=pendingnodes.front();
			pendingnodes.pop();
			int childnum;
			cout<<"Enter num of child of "<<front->data<<":"<<endl;
			cin>>childnum;
			for(int i=0;i<childnum;i++){
				int childdata;
				cout<<"Enter "<<i<<"th child of "<<front->data<<":"<<endl;
				cin>>childdata;
				treenode<int>*child=new treenode<int>(childdata);
				front->children.push_back(child);
				pendingnodes.push(front->children[i]);
						    }
			cout<<endl;
					    }
		return root;
						}

	void printlevelwise(treenode<int>*root){
			if(root==NULL){
				return;
					}
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
	int sumnodes(treenode<int>*root){
		int sum=root->data;
		for(int i=0;i<root->children.size();i++){
			sum += sumnodes(root->children[i]);
							}
		return sum;
					}
int main(){
	treenode<int>*root=takeinputlevelwise();
	printlevelwise(root);
	int sum=sumnodes(root);
	cout<<"Sum of nodes of tree:"<<sum<<endl;
	}
