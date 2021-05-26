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
void printlevelwise(treenode<int>*root){
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
					}
int countnodes(treenode<int>*root){
	if(root==NULL){
		return 0;
			}
	int count=1;
	for(int i=0;i<root->children.size();i++){
		count += countnodes(root->children[i]);
						}
	return count;
	}
int sumofnodes(treenode<int>*root){
	if(root==NULL){
		return 0;
			}
	int sum=root->data;
	for(int i=0;i<root->children.size();i++){
		sum += sumofnodes(root->children[i]);
						}
	return sum;
	}
int maxdatanode(treenode<int>*root){
	if(root==NULL){
		return 0;
			}
	int max=root->data;
	for(int i=0;i<root->children.size();i++){
		int MAX=maxdatanode(root->children[i]);
		if(MAX>max){
			max=MAX;
			    }
						}
	return max;
				}
int height(treenode<int>*root){
	int height1=0;
	for(int i=0;i<root->children.size();i++){
		int childheight = height(root->children[i]);
		if(childheight>height1){
			height1=childheight;
					}
						 }
	return height1+1;
	      			 }
int countleafnodes(treenode<int>*root){
	if(root->children.size()==0){
		return 1;
					}
	int count=0;
	for(int i=0;i<root->children.size();i++){
		count += countleafnodes(root->children[i]);
						}
	return count;
					}
void printleafnodes(treenode<int>*root){
	if(root->children.size()==0){
		cout<<root->data<<" ";
		return;
				    }
	for(int i=0;i<root->children.size();i++){
		printleafnodes(root->children[i]);
						}
					}
void printatdepthk(treenode<int>*root,int k){
	if(k==0){
		cout<<root->data<<" ";
		return;
		}
	for(int i=0;i<root->children.size();i++){
		printatdepthk(root->children[i],k-1);
						}
					}
void preordertraversal(treenode<int>*root){
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++){
		preordertraversal(root->children[i]);
						}
					}
void postordertraversal(treenode<int>*root){
	for(int i=0;i<root->children.size();i++){
		postordertraversal(root->children[i]);
						}
		cout<<root->data<<" ";
	
					   }
void inordertraversal(treenode<int>*root){
	for(int i=0;i<root->children.size()-1;i++){
		inordertraversal(root->children[i]);
		cout<<root->data<<" ";
						}
				}
bool findx(treenode<int>*root,int m){
	if(root->data==m){
		return true;
			}
	for(int i=0;i<root->children.size();i++){
		bool a=findx(root->children[i],m);
		if(a){
			return true;
		     }
						}
		return false;
				     }
int nodesgreater(treenode<int>*root,int m){
	int ans=0;
	for(int i=0;i<root->children.size();i++){
		ans += nodesgreater(root->children[i],m);
						}
	if(root->data>m){
		return ans+1;
			}
	else{
		return ans;
	    }
					}
int main(){
	treenode<int>*root=takeinputlevelwise();
	printlevelwise(root);
	int ans1=countnodes(root);
	cout<<ans1<<endl;
	int ans2=sumofnodes(root);
	cout<<ans2<<endl;
	int ans3=maxdatanode(root);
	cout<<ans3<<endl;
	int ans4=height(root);
	cout<<ans4<<endl;
	int ans5=countleafnodes(root);
	cout<<ans5<<endl;
	int k;
	cin>>k;
	printatdepthk(root,k);
	cout<<endl;
	printleafnodes(root);
	cout<<endl;	
	preordertraversal(root);
	cout<<endl;	
	postordertraversal(root);
	cout<<endl;	
	inordertraversal(root);
	int m;
	cin>>m;
	bool ans=findx(root,m);
	if(ans){
		cout<<"True"<<endl;
		}
	else{
		cout<<"False"<<endl;
	    }
	int ans6=nodesgreater(root,m);
	cout<<ans6<<endl;
	}
