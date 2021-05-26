#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
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
class node{
	public:
	int data;
	node*next;
		node(int data){
			this->data=data;
			next=NULL;
				}
	};
class pairans{
	public:
	node*head;
	node*tail;
	};

pairans Returnheadtail(binarytreenode<int>*root,pairans output){
	if(root==NULL){
		pairans output;
		output.head=NULL;
		output.tail=NULL;
		return output;
			}
	node*temp=new node(root->data);
	pairans leftans=Returnheadtail(root->left,output);
	pairans rightans=Returnheadtail(root->right,output);
	if(leftans.head!=NULL){
		output.head=leftans.head;
		leftans.tail->next=temp;	
				}
	else{
		output.head=temp;
	    }
	if(rightans.head!=NULL){
		temp->next=rightans.head;
		output.tail=rightans.tail;
				}
	else{
		output.tail=temp;
	    }
	return output;
						}

node*gettinghead(binarytreenode<int>*root){
	if(root==NULL)
		return NULL;
	pairans output;
	pairans put=Returnheadtail(root,output);
	return put.head;
					   }

void printll(node*head){
	if(head==NULL)
		return;
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
			 }
	cout<<endl;
			}
vector<int>*roottonodepath(binarytreenode<int>*root,int k){
	if(root==NULL)
		return NULL;
	if(root->data==k){
		vector<int>*v=new vector<int>();
		v->push_back(root->data);
		return v;
			}
	vector<int>*leftv=roottonodepath(root->left,k);
	if(leftv!=NULL){
		leftv->push_back(root->data);
		return leftv;
			}
		vector<int>*rightv=roottonodepath(root->right,k);
		if(rightv!=NULL){
			rightv->push_back(root->data);
			return rightv;
				}
		else{
		    	return NULL;
		    }
								}
vector<int>*roottonodepathinbst(binarytreenode<int>*root,int k){
	if(root==NULL)
		return NULL;
	if(root->data==k){
		vector<int>*v=new vector<int>();
		v->push_back(root->data);
		return v;
			}
	if(k<root->data){
		vector<int>*leftv=roottonodepathinbst(root->left,k);
		if(leftv!=NULL){
		leftv->push_back(root->data);
		return leftv;
				}
		else{
			return leftv;
		    }
			}
	else{
		vector<int>*rightv=roottonodepathinbst(root->right,k);
		if(rightv!=NULL){
		rightv->push_back(root->data);
		return rightv;
				}
		else{
			return rightv;
		    }
		}
								}
int main(){
	binarytreenode<int>*root=takeinput();
	//node*head=gettinghead(root);
	//printll(head);
	int k;
	cin>>k;
	vector<int>*v=roottonodepathinbst(root,k);
	if(v==NULL){
		cout<<" ";
		   }
	else{
	for(int i=0;i<v->size();i++){
		cout<<v->at(i)<<" ";
				   }
	   }
	cout<<endl;
	delete v;
	//printlevelwise(root);
 	 }
