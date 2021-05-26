#include<iostream>
#include<queue>
using namespace std;

//50 10 60 5 20 55 70 -1 -1 -1 -1 -1 -1 65 -1 -1 -1

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
		     };
binarytreenode<int>*takeinput(){
	int rootdata;
	cin>>rootdata;
	binarytreenode<int>*root=new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		binarytreenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int leftchilddata;
		cin>>leftchilddata;
		if(leftchilddata!=-1){
			binarytreenode<int>*leftchild=new binarytreenode<int>(leftchilddata);
			front->left=leftchild;
			pendingnodes.push(leftchild);
					}
		int rightchilddata;
		cin>>rightchilddata;
		if(rightchilddata!=-1){
			binarytreenode<int>*rightchild=new binarytreenode<int>(rightchilddata);
			front->right=rightchild;
			pendingnodes.push(rightchild);
					}
				      }
		return root;
				}

class BST{
	binarytreenode<int>*root;
	public:
		BST(binarytreenode<int>*node){
			root=node;
		     }
		~BST(){
			delete root;
			}
	private:
		binarytreenode<int>*insertdata(int data,binarytreenode<int>*root){
			if(root==NULL){
				binarytreenode<int>*node=new binarytreenode<int>(data);
				return node;
					}
			if(data<root->data){
				binarytreenode<int>*small=insertdata(data,root->left);
				root->left=small;
				return root;
					   }
			else{
				binarytreenode<int>*small=insertdata(data,root->right);
				root->right=small;
				return root;
			    }
										}
	public:
		binarytreenode<int>*insert(int data){
				return insertdata(data,root);
					}
	private:
		binarytreenode<int>*deletenode(int data,binarytreenode<int>*root){
			if(root==NULL){
				return NULL;
					}	
			if(data==root->data){
				if(root->left==NULL && root->right==NULL){
					delete root;
					return NULL;
									  }
				else if(root->left==NULL){	
					binarytreenode<int>*temp=root->right;
					root->right=NULL;
					delete root;
					return temp; 
							}
				else if(root->right==NULL){
					binarytreenode<int>*temp=root->left;
					root->left=NULL;
					delete root;
					return temp;
							  }
				else{
					binarytreenode<int>*leftmax=root->left;
					while(leftmax->right!=NULL){
						leftmax=leftmax->right;
								}	
					int lmax=leftmax->data;
					root->data=lmax;
					root->left=deletenode(lmax,root->left);
					return root;
				     }
						}
			else if(data<root->data){
				binarytreenode<int>*temp=deletenode(data,root->left);
				root->left=temp;
				return root;
						}
			else{
				binarytreenode<int>*temp=deletenode(data,root->right);
			    	root->right=temp;
				return root;
			    }
						
										}
	public:
		binarytreenode<int>*deletenode(int data){
			return deletenode(data,root);
									}
	private:
		bool searchdata(int data,binarytreenode<int>*root){
			if(root==NULL)
				return false;
			if(data==root->data){
				return true;
					    }
			if(data<root->data){
				return searchdata(data,root->left);
					    }
			else{
				return searchdata(data,root->right);
						 }
			
			}	

	public:
		bool checkdata(int data){
			return searchdata(data,root);
				      }
	};

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
	binarytreenode<int>*root=takeinput();
	//printlevelwise(root);
	int data;
	cin>>data;
	BST b(root);
	//bool ans=b.checkdata(data);
	//cout<<ans<<endl;
	//root=b.insert(data);
	root=b.deletenode(data);
	printlevelwise(root);
	}
