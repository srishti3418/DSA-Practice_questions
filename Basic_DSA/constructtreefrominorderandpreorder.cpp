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

binarytreenode<int>*constructtree(int *inorder,int inorderstart,int inorderend,int *preorder,int preorderstart,int preorderend){
	if(inorderstart>inorderend || preorderstart>preorderend)
		return NULL;
	int root=preorder[preorderstart];
	binarytreenode<int>*rootnode=new binarytreenode<int>(root);
	int k=inorderstart;
	while(inorder[k]!=root){
		k++;
				}
	rootnode->left=constructtree(inorder,inorderstart,k-1,preorder,preorderstart+1,preorderstart+(k-inorderstart));
	rootnode->right=constructtree(inorder,k+1,inorderend,preorder,preorderend+(k-inorderend)+1,preorderend);
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
	int preorder[n];
	for(int i=0;i<n;i++){
		cin>>preorder[i];
			    }
	binarytreenode<int>*root=constructtree(inorder,0,n-1,preorder,0,n-1);
	printlevelwise(root);
	delete root;
	}
