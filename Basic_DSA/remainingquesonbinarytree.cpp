#include<iostream>
#include<queue>
#include<cmath>
#include<climits>
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
template <typename T,typename V>
class pairans{
	public:
	T max;
	V min;
	 };

class boolint{
	public:
	bool balanced;
	int height;
	     };
binarytreenode<int>*takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	binarytreenode<int>*root=new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		binarytreenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1){
		binarytreenode<int>*leftchild=new binarytreenode<int>(leftdata);
		front->left=leftchild;
		pendingnodes.push(leftchild);
				}
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1){
		binarytreenode<int>*rightchild=new binarytreenode<int>(rightdata);
		front->right=rightchild;
		pendingnodes.push(rightchild);
				 }
				   }
	return root;
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
pair<int,int> heightdiameter(binarytreenode<int>*root){
	if(root==NULL){
		pair<int,int> p;
		p.first=0;
		p.second=0;
		return p;
			}
	pair<int,int> leftanswer=heightdiameter(root->left);
	pair<int,int> rightanswer=heightdiameter(root->right);
	int ld=leftanswer.second;
	int lh=leftanswer.first;
	int rd=rightanswer.second;
	int rh=rightanswer.first;
	
	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int> p;
	p.first=height;
	p.second=diameter;
	return p;
							}
pairans<int,int> maxmin(binarytreenode<int>*root){
	if(root==NULL){
		pairans<int,int> p;
		p.max=INT_MIN;
		p.min=INT_MAX;
		return p;
			}
	pairans<int,int> leftanswer=maxmin(root->left);
	pairans<int,int> rightanswer=maxmin(root->right);
	int leftmax=leftanswer.max;
	int leftmin=leftanswer.min;
	int rightmax=rightanswer.max;
	int rightmin=rightanswer.min;
	
	pairans<int,int> p;
	p.max=max(leftmax,rightmax);
	p.min=min(leftmin,rightmin);
	if(root->data>p.max){
		p.max=root->data;
			   }
	if(root->data<p.min){
		p.min=root->data;
			  }
	return p;
						}
int sumofnodes(binarytreenode<int>*root){
	if(root==NULL)
		return 0;
	int leftans=0;
	int rightans=0;
	leftans += sumofnodes(root->left);
	rightans += sumofnodes(root->right);
	return root->data+leftans+rightans;
					 }
boolint isbalanced(binarytreenode<int>*root){
	if(root==NULL){
		boolint b;
		b.balanced=true;
		b.height=0;
		return b;
		      }
	boolint leftans=isbalanced(root->left);
	boolint rightans=isbalanced(root->right);
	bool flag=true;
	if(!(leftans.balanced) || !(rightans.balanced) || abs(leftans.height-rightans.height)>1){
		flag=false;
											     }
	boolint b;
	b.balanced=flag;
	b.height=1+max(leftans.height,rightans.height);
	return b;
						}
bool finalcheck(binarytreenode<int>*root){
	if(root==NULL)
		return true;
	boolint pairans=isbalanced(root);
	if(pairans.balanced){
		return true;
			    }
	return false;
					}
int height(binarytreenode<int>*root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
					}
void printatlevels(binarytreenode<int>*root){
	if(root==NULL)
		return;
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	int count=0;
	while(!pendingnodes.empty()){
		binarytreenode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		if(pendingnodes.size()==0 && count==0){
		
		cout<<front->data<<" ";
		count++;
					  }
		count++;
		if(front->left!=NULL){
			cout<<endl;
			if(count%2!=0 && front->right!=NULL){
				cout<<front->left->data<<" ";
				 }
			else if(count%2==0 && front->right!=NULL){
				cout<<front->right->data<<" ";
			    }
			else{
				if(front->right==NULL)
					cout<<front->left->data<<endl;
			   }
			pendingnodes.push(front->left);
					}
		if(front->right!=NULL){
			if(front->left==NULL){
				cout<<endl;
						}
			if(count%2!=0 && front->left!=NULL){
				cout<<front->right->data<<" ";
				   }
			else if(count%2==0 && front->left!=NULL){
				cout<<front->left->data<<" ";
			     }
			else{
				if(front->left==NULL)
					cout<<front->right->data<<" ";
			    }
			pendingnodes.push(front->right);
					}
				     }
						}
binarytreenode<int>*deleteleafnodes(binarytreenode<int>*root){
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right == NULL){
		return NULL;
						    }
	binarytreenode<int>*leftroot=deleteleafnodes(root->left);
	binarytreenode<int>*rightroot=deleteleafnodes(root->right);
	root->left=leftroot;
	root->right=rightroot;
	return root;
					      }
void nodeswithoutsibling(binarytreenode<int>*root){
	if(root==NULL)
		return;
	if(root->left!=NULL && root->right==NULL)
			cout<<root->left->data<<" ";
	if(root->right!=NULL && root->left==NULL)			
			cout<<root->right->data<<" ";					
													
	nodeswithoutsibling(root->left);
	nodeswithoutsibling(root->right);
	}

int main(){
	binarytreenode<int>*root=takeinputlevelwise();
	printlevelwise(root);
	pair<int,int> p=heightdiameter(root);
	cout<<"Height:"<<p.first<<endl;
	cout<<"Diameter:"<<p.second<<endl;
	pairans<int,int> P=maxmin(root);
	cout<<"Max:"<<P.max<<endl;
	cout<<"Min:"<<P.min<<endl;
	int ans=sumofnodes(root);
	cout<<ans<<endl;
	bool checkbalanced=finalcheck(root);
	if(checkbalanced){
		cout<<"True"<<endl;
			}
	else{
		cout<<"False"<<endl;
	    }
	//root=deleteleafnodes(root);
	printatlevels(root);
	cout<<endl;
	//nodeswithoutsibling(root);
	delete root;
	  }
