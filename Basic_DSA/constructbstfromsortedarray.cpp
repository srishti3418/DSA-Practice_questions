#include<iostream>
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
		     };

binarytreenode<int>*constructtree(int arr[],int si,int ei){
	if(si>ei)
		return NULL;
	int mid=(si+ei)/2;
	binarytreenode<int>*root=new binarytreenode<int>(arr[mid]);
	binarytreenode<int>*leftpart=constructtree(arr,si,mid-1);
	binarytreenode<int>*rightpart=constructtree(arr,mid+1,ei);
	root->left=leftpart;
	root->right=rightpart;
	return root;
								}
void preorder(binarytreenode<int>*root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
        return;
			       }

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
			     }
	binarytreenode<int>*root=constructtree(arr,0,n-1);
	preorder(root);
	}
