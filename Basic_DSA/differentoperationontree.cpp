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
	/*void printlevelwise(treenode<int>*root){
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
							}*/
	int maxnode(treenode<int>*root){
		int max=root->data;
		for(int i=0;i<root->children.size();i++){
			int MAX=maxnode(root->children[i]);
			if(MAX>max){
				max=MAX;
				    }
			
							}
		return max;
					}
	int height(treenode<int>*root){
		int h=0;
		for(int i=0;i<root->children.size();i++){
			 int h1=height(root->children[i]);
			 if(h1>h){
				h=h1;
				}
							}
		return h+1;
					}
	void printatlevelk(treenode<int>*root,int k){
		if(root==NULL){
			return;
				}
		if(k==0){
			cout<<root->data<<endl;
			}
		for(int i=0;i<root->children.size();i++){
			printatlevelk(root->children[i],k-1);
							}
						}
	int numofleaf(treenode<int>*root){
		int count=0;
		if(root->children.size()==0){
			  count++;
					    }
		for(int i=0;i<root->children.size();i++){
			count += numofleaf(root->children[i]);
						}
		return count;
					}
	void preorder(treenode<int>*root){
		if(root==NULL){
			return;
				}
		cout<<root->data<<" ";
		for(int i=0;i<root->children.size();i++){
			preorder(root->children[i]);
							}
		}
	void postorder(treenode<int>*root){
		if(root==NULL){
			return;
				}
		for(int i=0;i<root->children.size();i++){
			postorder(root->children[i]);
							}
		 cout<<root->data<<" ";
					}
int main(){
	treenode<int>*root=takeinputlevelwise();
	//printlevelwise(root);
	int maxdata=maxnode(root);
	cout<<maxdata<<endl;
	int H=height(root);
	cout<<H<<endl;
	int k;
	cin>>k;
	printatlevelk(root,k);
	int num=numofleaf(root);
	cout<<num<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	}
