#include<iostream>
#include<queue>
#include<climits>
using namespace std;

// 5 3 8 2 4 6 9 -1 -1 -1 -1 -1 7 -1 -1 -1 -1

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
binarytreenode<int>*searchinbst(binarytreenode<int>*root,int k){
	if(root==NULL)
		return NULL;
	if(root->data==k)
		return root;
	if(root->data>k){
		return searchinbst(root->left,k);
		        }
	if(root->data<k){
		return searchinbst(root->right,k);
			}
	return NULL;
		}
void searchnodesinrange(binarytreenode<int>*root,int m,int n){
	if(root==NULL)
		return;
	if(root->data>=m && root->data<=n){
		searchnodesinrange(root->left,m,n);
		cout<<root->data<<" ";
		searchnodesinrange(root->right,m,n);
					}
	if(root->data<m){
		searchnodesinrange(root->right,m,n);
		return;
			}
	else if(root->data>n){
		searchnodesinrange(root->left,m,n);
		return;
			     }
								}
bool checktree(binarytreenode<int>*root,int minima,int maxima){
	if(root==NULL)
		return true;
	if(root->data<minima || root->data>maxima){
		return false;
									}
	bool leftans=checktree(root->left,minima,root->data);
	bool rightans=checktree(root->right,root->data,maxima);
	return leftans && rightans;
								}
int maximum(binarytreenode<int>*root){
	if(root==NULL)
		return INT_MIN;
	return max(root->data,max(maximum(root->left),maximum(root->right)));
					}
int minimum(binarytreenode<int>*root){
	if(root==NULL)
		return INT_MAX;
	return min(root->data,min(minimum(root->left),minimum(root->right)));
				     }					
bool checktree2(binarytreenode<int>*root){
	if(root==NULL)
		return true;
	int leftmax=maximum(root->left);
	int rightmin=minimum(root->right);
	return (root->data>leftmax) && (root->data<rightmin) && (checktree2(root->left)) && (checktree2(root->right));
					}

class IsBst{
	public:
	int Max;
	int Min;
	bool check;
	    };

IsBst checkbst3(binarytreenode<int>*root){
	if(root==NULL){
		IsBst output;
		output.Min=INT_MAX;
		output.Max=INT_MIN;
		output.check=true;
		return output;
			}
	IsBst leftans=checkbst3(root->left);
	IsBst rightans=checkbst3(root->right);
	int maximum=max(root->data,max(leftans.Max,rightans.Max));
	int minimum=min(root->data,min(leftans.Min,rightans.Min));
	IsBst output;
	output.Max=maximum;
	output.Min=minimum;
	output.check=(root->data>leftans.Max) && (root->data<rightans.Min) && (leftans.check) && (rightans.check);
	return output;
					   }
bool checktree3(binarytreenode<int>*root){
	if(root==NULL)
		return true;
	IsBst ans=checkbst3(root);
	if(ans.check)
		return true;
	else
		return false;
					}
int main(){
	binarytreenode<int>*root=takeinput();
	printlevelwise(root);
	/*int k;
	cin>>k;
	binarytreenode<int>*node=searchinbst(root,k);
	if(node==NULL){
		cout<<" "<<endl;
		      }
	else{
	cout<<node->data<<endl;
	int m,n;
	cin>>m>>n;
	searchnodesinrange(root,m,n);*/
	int minima=INT_MIN;
	int maxima=INT_MAX;
	bool ans=checktree(root,minima,maxima);
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	cout<<checktree2(root)<<endl;
	cout<<checktree3(root)<<endl;
	 }
	
