#include<iostream>
#include<queue>
#include<climits>
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
			pendingnodes.push(leftchild);
			front->left=leftchild;
					}
		int rightchilddata;
		cin>>rightchilddata;
		if(rightchilddata!=-1){
			binarytreenode<int>*rightchild=new binarytreenode<int>(rightchilddata);
			pendingnodes.push(rightchild);
			front->right=rightchild;
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
			cout<<front->left->data;
			pendingnodes.push(front->left);
					}
		if(front->right!=NULL){
			if(front->left!=NULL){
			cout<<",";
					    }
			cout<<front->right->data;
			pendingnodes.push(front->right);
					}
		cout<<endl;
				   }
						}
/*bool hasdata(binarytreenode<int>*root,int n){
	if(root==NULL)
		return false;
	if(root->data==n){
		root->data=INT_MIN;
		return true;
			}
	else{
		return hasdata(root->left,n) || hasdata(root->right,n);
	   }			
						}

void findpairsum(binarytreenode<int>*root,int s){
	if(root==NULL)
		return;
	if(root->data<=s){
		int p=s-root->data;
		if(p!=(s/2)){
		bool ans=hasdata(root,p);
		if(ans){
			cout<<root->data<<" "<<p<<endl;
			}
			     }
		else{
			bool ans1=hasdata(root->left,p);
			if(ans1){
				cout<<root->data<<" "<<p<<endl;
				}
			else{
				bool ans2=hasdata(root->right,p);
				if(ans2){
					cout<<root->data<<" "<<p<<endl;
					}
			    }
		    }
			}
	findpairsum(root->left,s);
	findpairsum(root->right,s);
							}*/
void merge(int arr[],int si,int ei){
	int mid=(ei+si)/2;
	int i=si;
	int j=mid+1;
	int output[100];
	int k=0;
	while(i<=mid && j<=ei){
		if(arr[i]<=arr[j]){
			output[k]=arr[i];
			i++;
			k++;
				}
		else{
			output[k]=arr[j];
			j++;
			k++;
		     }
				}
	while(i<=mid){
		output[k]=arr[i];
		k++;
		i++;
			}
	while(j<=ei){
		output[k]=arr[j];
		k++;
		j++;
		    }
	int p=0;
	for(int u=si;u<=ei;u++){
		arr[u]=output[p];
		p++;
			    }
					}
void mergesort(int arr[],int si,int ei){
	if(si>=ei)
		return;
	int mid=(ei+si)/2;
	mergesort(arr,si,mid);
	mergesort(arr,mid+1,ei);
	merge(arr,si,ei);
	return;
					}
void preorder(binarytreenode<int>*root,int arr[],int &i){
	if(root==NULL)
		return;
	arr[i]=root->data;
	cout<<arr[i]<<" ";
	i++;
	preorder(root->left,arr,i);
	preorder(root->right,arr,i);
	
							}
void pairsum(binarytreenode<int>*root,int arr[],int n,int s){
	if(root==NULL)
		return;
	int i=0;
	int j=n-1;
	while(i<j){
		if((arr[i]+arr[j])==s){
			cout<<arr[i]<<" "<<arr[j]<<endl;
			i++;
			j--;
					}
		else if(arr[i]+arr[j]>s){
			j--;
					}
		else{
			i++;
		    }
		}
							}
binarytreenode<int>*createandinsertduplicate(binarytreenode<int>*root){
	if(root==NULL)
		return NULL;
	binarytreenode<int>*node=new binarytreenode<int>(root->data);
	binarytreenode<int>*temp=root->left;
	root->left=node;
	node->left=temp;
	binarytreenode<int>*leftpart=createandinsertduplicate(temp);
	binarytreenode<int>*rightpart=createandinsertduplicate(root->right);
	node->left=leftpart;
	root->right=rightpart;
	return root;
									}
binarytreenode<int>*findlca(binarytreenode<int>*root,int m,int n){
	if(root==NULL)
		return NULL;
	if(root->data==m || root->data==n){
		return root;
					   }
	binarytreenode<int>*leftpart=findlca(root->left,m,n);
	binarytreenode<int>*rightpart=findlca(root->right,m,n);
	if(leftpart==NULL && rightpart==NULL)
		return NULL;
	else if(leftpart==NULL || rightpart==NULL){
		if(leftpart!=NULL)
			return leftpart;
		else if(rightpart!=NULL){
			return rightpart;
					}
						}
	else{
		return root;
	    }
									}
binarytreenode<int>*findlcainbst(binarytreenode<int>*root,int m,int n){
	if(root==NULL)
		return NULL;
	if(root->data==m || root->data==n){
		return root;
					   }
	if(m<root->data && n<root->data)
		return findlcainbst(root->left,m,n);
	else if(m>root->data && n>root->data)
		return findlcainbst(root->right,m,n);
	else{
		binarytreenode<int>*leftpart=findlcainbst(root->left,m,n);
		binarytreenode<int>*rightpart=findlcainbst(root->right,m,n);
		if(leftpart==NULL && rightpart==NULL)
			return NULL;
		else if(leftpart==NULL || rightpart==NULL){
			if(leftpart!=NULL)
				return leftpart;
			else if(rightpart!=NULL)
				return rightpart;
							   }
		else{
			return root;
		   }
	   }
									}
class fourthings{
	public:
	int maximum;
	int minimum;
	bool IsBST;
	int height;
		};


fourthings largestbst(binarytreenode<int>*root){
	if(root==NULL){
		fourthings f;
		f.maximum=INT_MIN;
		f.minimum=INT_MAX;
		f.IsBST=true;
		f.height=0;
		return f;
		       }
	fourthings leftpart=largestbst(root->left);
	fourthings rightpart=largestbst(root->right);
	int h=max(leftpart.height,rightpart.height);
	int Max=max(rightpart.maximum,max(root->data,leftpart.maximum));
	int Min=min(leftpart.minimum,min(root->data,rightpart.minimum));
	if(leftpart.IsBST==true && rightpart.IsBST==true){
	if(root->data>leftpart.maximum && root->data<rightpart.minimum){
		fourthings f;
		f.maximum=Max;
		f.minimum=Min;
		f.IsBST=true;
		f.height=h+1;
		return f;
							}
	else{
		if(leftpart.IsBST)
			return leftpart;
		else if(rightpart.IsBST)
			return rightpart;
		else{	
			fourthings f;
			f.maximum=Max;
			f.minimum=Min;
			f.IsBST=false;
			f.height=0;
			return f;
		     }
	
	
					           }}
	else{
		if(leftpart.IsBST)
			return leftpart;
		else if(rightpart.IsBST)
			return rightpart;
		else{	
			fourthings f;
			f.maximum=Max;
			f.minimum=Min;
			f.IsBST=false;
			f.height=0;
			return f;
		     }
	    }
}
int sumateachnodes(binarytreenode<int>*root,int sum){
	if(root==NULL)
		return sum;
	sum=sumateachnodes(root->right,sum);
	sum += root->data;
	root->data=sum;
	sum=sumateachnodes(root->left,sum);
	return sum;
						}
int main(){
	binarytreenode<int>*root=takeinput();
	/*printlevelwise(root);
	//root=createandinsertduplicate(root);
	//printlevelwise(root);
	//int s;
	//cin>>s;
	//findpairsum(root,s);
	int arr[100];
	int i=0;
	preorder(root,arr,i);
	cout<<endl;
	mergesort(arr,0,i-1);
	//cout<<endl<<i<<endl;
	for(int y=0;y<i;y++){
		cout<<arr[y]<<" ";
			    }
	cout<<endl;
	int s;
	cin>>s;
	pairsum(root,arr,i,s);
	int m,n;
	cin>>m>>n;
	binarytreenode<int>*ans=findlcainbst(root,m,n);
	if(ans==NULL)
		cout<<"-1"<<endl;
	else
		cout<<ans->data<<endl;*/
	//fourthings ans=largestbst(root);
	//cout<<ans.height<<endl;
	int ans=sumateachnodes(root,0);
	printlevelwise(root);
 }
