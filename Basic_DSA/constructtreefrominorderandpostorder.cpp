#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class binarytreenode{
	public:
	T data;
	binarytreenode<T>*left;
	binarytreenode<T>*right;
		binarytreenode(T data){
			this->data=data;
			left=NULL;
			right=NULL;
					}
		~binarytreenode(){
			delete left;
			delete right;
				}
		};
binarytreenode<int>*constructtree(int *inorder,int inordersp,int inorderep,int *postorder,int postordersp,int postorderep){
	if(inordersp>inorderep || postordersp>postorderep)
		return NULL;
	int root=postorder[postorderep];
	binarytreenode<int>*rootnode=new binarytreenode<int>(root);
	int k=inordersp;
	while(inorder[k]!=root){
		k++;
				}
	rootnode->left=constructtree(inorder,inordersp,k-1,postorder,postordersp,postordersp+(k-inordersp)-1);
	rootnode->right=constructtree(inorder,k+1,inorderep,postorder,postorderep+k-inorderep,postorderep-1);
	return rootnode;
	}
void printlevelwise(binarytreenode<int>*root){
	if(root==NULL)
		return;
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		binarytreenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		if(front->left!=NULL){
			cout<<front->left->data<<",";
			pendingnodes.push(front->left);
					}
		if(front->right!=NULL){
			cout<<front->right->data<<",";
			pendingnodes.push(front->right);
					}
		cout<<endl;
					}
						}
int main(){
	int n;
	cin>>n;
	int inorder[n];
	for(int i=0;i<n;i++){
		cin>>inorder[i];
			    }
	int postorder[n];
	for(int i=0;i<n;i++){
		cin>>postorder[i];
			    }
	binarytreenode<int>*root=constructtree(inorder,0,n-1,postorder,0,n-1);
	printlevelwise(root);
	delete root;
	}
