#include<iostream>
#include<queue>
#include<vector>
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
treenode<int>*nodewithmaxchildsum(treenode<int>*root){
	treenode<int>*ans=root;
	int sum=root->data;
	for(int i=0;i<root->children.size();i++){
		sum += root->children[i]->data;
						}
	
	for(int i=0;i<root->children.size();i++){
		treenode<int>*a=nodewithmaxchildsum(root->children[i]);
		int asum=a->data;
		for(int i=0;i<a->children.size();i++){
			asum += a->children[i]->data;
							}
		if(asum>sum){
			sum=asum;
			ans=a;
			     }
						}
		return ans;
					   }

/*bool comparetrees(treenode<int>*root1,treenode<int>*root2){
	for(int i=0,j=0;i<root1->children.size(),j<root2->children.size();i++,j++){
		bool t=comparetrees(root1->children[i],root2->children[j]);
		if(t){
			if(root1->data==root2->data)
				return true;
			else
				return false;
		     }
		 						
									       	}
	return false;
							}*/
bool isidentical(treenode<int>*root1,treenode<int>*root2){
		if(root1==NULL && root2==NULL){
			return true;
						}
		if((root1!=NULL && root2==NULL) || (root2!=NULL && root1==NULL)){
			return false;
										}
		if((root1->data!=root2->data) || (root1->children.size()!=root2->children.size())){
			return false;
								   }
		int i=0;
		while(i<root1->children.size()){
			treenode<int>*child1=root1->children[i];
			treenode<int>*child2=root2->children[i];
			if(isidentical(child1,child2)){
				i++;
						       }
			else{
				return false;
			    }
						}
		return true;
							}
treenode<int>*nextlarger(treenode<int>*root,int n){
	if(root==NULL){
		return NULL;
			}
	treenode<int>*ans=NULL;
	if(root->data>n){
		ans=root;
			}
	for(int i=0;i<root->children.size();i++){
		treenode<int>*smallans=nextlarger(root->children[i],n);
		if(ans==NULL){
			ans=smallans;
			     }
		if(smallans!=NULL && smallans->data<ans->data){
			ans=smallans;
				}
						}
	return ans;
					}
treenode<int>*nextlargest(treenode<int>*root){
	if(root==NULL){
		return root;
			}
	treenode<int>*secmax=root;
	for(int i=0;i<root->children.size();i++){
		treenode<int>*smallsecmax=nextlargest(root->children[i]);
		if(smallsecmax->data>secmax->data){
			secmax=smallsecmax;
						  }
					        }
	return secmax;
					    }
void replacenodewithdepth(treenode<int>*root,int depth){
	if(root==NULL){
		return;
			}
	root->data=depth;
	for(int i=0;i<root->children.size();i++){
		replacenodewithdepth(root->children[i],depth+1);
						}
							}
int main(){
	treenode<int>*root1=takeinputlevelwise();
	/*treenode<int>*root2=takeinputlevelwise();
	bool ans=isidentical(root1,root2);
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	int n;
	cin>>n;
	treenode<int>*ans=nextlarger(root1,n);
	cout<<ans->data<<endl;
	treenode<int>*ans=nextlargest(root1);
	cout<<ans->data<<endl;*/
	replacenodewithdepth(root1,0);
	printlevelwise(root1);
	//treenode<int>*ans=nodewithmaxchildsum(root);
	//cout<<ans->data<<endl;	
	}
//http://www.cplusplus.com/reference/algorithm/sort/