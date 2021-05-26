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
	cout<<"Enter root data:"<<endl;
	cin>>rootdata;
	treenode<int>*root=new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		treenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int childnum;
		cout<<"Enter the number of child of"<<front->data<<":"<<endl;
		cin>>childnum;
		for(int i=0;i<childnum;i++){
			int childdata;
			cout<<"Enter the "<<i<<"th child of"<<front->data<<endl;
			cin>>childdata;
			treenode<int>*child=new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
					    }
					}
		return root;
				}
	void printnodelevelwise(treenode<int>*root){
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
	int numnodes(treenode<int>*root){
		int num=1;
		for(int i=0;i<root->children.size();i++){
			num += numnodes(root->children[i]);
							}
		return num;
					}
int main(){
	treenode<int>*root=takeinputlevelwise();
	printnodelevelwise(root);
	int res=numnodes(root);
	cout<<"Number of nodes in a tree:"<<res<<endl;
	}
