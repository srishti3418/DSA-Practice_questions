#include<iostream>
#include<string>
using namespace std;

class trienode{
	public:
	char data;
	trienode**children;
	bool isterminal;
		trienode(char data){
			this->data=data;
			children=new trienode*[26];
			for(int i=0;i<26;i++){
				children[i]=NULL;
						}
			isterminal=false;
				   }
		};
class trie{
	trienode *root;
	public:
		trie(){
			root=new trienode('\0');
			}
		void insert(trienode*root,string word){
			if(word.size()==0){
				root->isterminal=true;
				return;
					   }
			trienode*child;
				int index=word[0]-'a';
				if(root->children[index]!=NULL){
					child=root->children[index];
								}
				else{
					child=new trienode(word[0]);
					root->children[index]=child;
				     }						
			insert(child,word.substr(1));				
						}
		void insert(string word){
			insert(root,word);
			return;
					}
		bool searchword(trienode*root,string word){
			if(word.size()==0){
				return true;
					   }
			trienode*child;
			int index=word[0]-'a';
			if(root->children[index]!=NULL){
				child=root->children[index];
				return searchword(child,word.substr(1));
							}
			else
				return false;
							  }
		bool searchword(string word){
			return searchword(root,word);
					    }
		void searchpattern(trienode*root,string word){
			if(word.size()==0){
				if(root->isterminal==true){
					cout<<root->data<<endl;
					trienode*smallchild;
					for(int i=0;i<26;i++){
						if(root->children[i]!=NULL){
							smallchild=root->children}}
							   }
				else
					return;
					}
			trinode*child;
			int index=word[0]-'a';
			if(root->children[index]!=NULL){
				child=root->children[index];
				searchpattern(child,word.substr(1));
				}
			else
				return;
			trienode*smallchild;
			while(!smallchild->isterminal==false){
			for(int i=0;i<26;i++){
				if(child->children[i]!=NULL){
					smallchild=root->children[i];
							    }}
							   }}
			}
			};

int main(){
	trie t;
	int n;
	cin>>n;
	string word;
	/*for(int j=0;j<n;j++){
	cin>>word;
	for(int i=0;i<word.size();i++){
		t.insert(word.substr(i));
					}
			   }*/
	for(int i=0;i<n;i++){
		cin>>word;
		t.insert(word);
			   }
	string pattern;
	cin>>pattern;
	/*bool ans=t.searchword(pattern);
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;*/
	t.searchpattern(pattern);
	}
