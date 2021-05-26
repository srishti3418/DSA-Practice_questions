#include<iostream>
#include<queue>
#include<cmath>
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
binarytreenode<int>*takeinputlevelwise(){
	int rootdata;
	cout<<"Enter root data"<<endl;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
			}
	binarytreenode<int>*root=new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		binarytreenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int leftchilddata;
		cout<<"Enter left child of "<<front->data<<endl;
		cin>>leftchilddata;
		if(leftchilddata!=-1){
			binarytreenode<int>*leftchild=new binarytreenode<int>(leftchilddata);
			front->left=leftchild;
			pendingnodes.push(leftchild);
				}
		int rightchilddata;
		cout<<"Enter right child of "<<front->data<<endl;
		cin>>rightchilddata;
		if(rightchilddata!=-1){
			binarytreenode<int>*rightchild=new binarytreenode<int>(rightchilddata);
			front->right=rightchild;
			pendingnodes.push(rightchild);
					}
				    }
	return root;
					     }
void printlevelwise(binarytreenode<int>*root){
	if(root==NULL){
		return;
		      }
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
int numofnodes(binarytreenode<int>*root){
	if(root==NULL){
		return 0;
			}
	int smallans1=numofnodes(root->left);
	int smallans2=numofnodes(root->right);
	return 1+smallans1+smallans2;
					}
bool findx(binarytreenode<int>*root,int x){
	if(root==NULL){
		return false;
			}
	if(root->data==x)
		return true;
	bool smallans1=findx(root->left,x);
	bool smallans2=findx(root->right,x);
	return smallans1||smallans2;
					}
int height(binarytreenode<int>*root){
	if(root==NULL){
		return 0;
			}
	return max(height(root->left),height(root->right))+1;
				}
void mirror(binarytreenode<int>*root){
	if(root==NULL)
		return;
	binarytreenode<int>*temp=root->left;
	root->left=root->right;
	root->left=temp;
	mirror(root->left);
	mirror(root->right);
					}
void inorder(binarytreenode<int>*root){
	if(root==NULL){
		return;
			}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
					}
void preorder(binarytreenode<int>*root){
	if(root==NULL){
		return;
			}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
					}
void postorder(binarytreenode<int>*root){
	if(root==NULL){
		return;
			}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
					}
int main(){
	binarytreenode<int>*root=takeinputlevelwise();
	printlevelwise(root);
	int ans=numofnodes(root);
	cout<<ans<<endl;
	int x;
	cin>>x;
	bool ans1=findx(root,x);
	if(ans1){
		cout<<"True"<<endl;
	        }
	else{
		cout<<"False"<<endl;
	   }
	int h=height(root);
	cout<<h<<endl;
	mirror(root);
	printlevelwise(root);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	delete root;
	  }
