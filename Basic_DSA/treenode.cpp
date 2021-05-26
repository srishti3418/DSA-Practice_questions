#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class treenode{
	public:
	T data;
	vector<treenode*> children;
		treenode(int data){
			this->data=data;
				  }
		};
	treenode<int>*takeinput(){
		int rootdata;
		cout<<"Enter the data:"<<endl;
		cin>>rootdata;
		treenode<int>*root=new treenode<int>(rootdata);
		int n;
		cout<<"Enter number of children of "<<rootdata<<endl;
		cin>>n;
		for(int i=0;i<n;i++){
			treenode<int>*child=takeinput();
			root->children.push_back(child);
					}
			return root;
		}
	treenode<int>*takeinputlevelwise(){
		int rootdata;
		cout<<"Enter the rootdata:"<<endl;
		cin>>rootdata;
		treenode<int>*root=new treenode<int>(rootdata);
		queue<treenode<int>*> pendingnodes;
		pendingnodes.push(root);
		while(!pendingnodes.empty()){
			treenode<int>*front=pendingnodes.front();
			pendingnodes.pop();
			int childnum;
			cout<<"Enter the number of child of"<<front->data<<endl;
			cin>>childnum;
			for(int i=0;i<childnum;i++){
				int childdata;
				cout<<"Enter the "<<i<<"th child "<<endl;
				cin>>childdata;
				treenode<int>*child=new treenode<int>(childdata);
				front->children.push_back(child);
				pendingnodes.push(child);
						    }
					}
			return root;
						}
	void printtree(treenode<int>*root){
		if(root==NULL){
			return;
				}
		cout<<root->data<<":";
		for(int i=0;i<root->children.size();i++){
			cout<<root->children[i]->data<<",";
							}
		cout<<endl;
		for(int i=0;i<root->children.size();i++){
			printtree(root->children[i]);
							}
					}
	void printtreelevelwise(treenode<int>*root){
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
int main(){
	/*treenode<int>*root=new treenode<int>(1);
	treenode<int>*node1=new treenode<int>(2);
	treenode<int>*node2=new treenode<int>(3);

	root->children.push_back(node1);
	root->children.push_back(node2);*/

	treenode<int>*root=takeinputlevelwise();
	printtreelevelwise(root);
	}	
