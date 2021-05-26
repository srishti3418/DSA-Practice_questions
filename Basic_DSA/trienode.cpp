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

class operations{
	trienode*root;
	public:
		operations(){
			root=new trienode('\0');
			   }
	void insertword(trienode*root,string word){
		if(word.size()==0){
			root->isterminal=true;
			return;
				}
		int index=word[0]-'a';
		trienode*child;
		if(root->children[index]!=NULL){
			child=root->children[index];
						}
		else{
			child=new trienode(word[0]);
			root->children[index]=child;
		    }
		insertword(child,word.substr(1));
						}
	void insertword(string word){
		insertword(root,word);
		return;
					}
	bool searchword(trienode*root,string word){
		if(word.size()==0){
			return root->isterminal;
				  }
		int index=word[0]-'a';
		trienode*child;
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
	void remove(trienode*root,string word){
		if(word.size()==0){
			root->isterminal=false;
			return;
				}
		trienode*child;
		int index=word[0]-'a';
		if(root->children[index]!=NULL){
			child=root->children[index];
						}
		else{
			return;
		    }
		remove(child,word.substr(1));
		if(child->isterminal==false){
			for(int i=0;i<26;i++){
				return;
				  	      }
			delete child;
			root->children[index]=NULL;
					     }
					}
		void remove(string word){
			remove(root,word);
			return;
					}
		};

int main(){
	string word;
	operations o;
	for(int i=0;i<4;i++){
		cin>>word;
		o.insertword(word);
			     }
	string Sword;
	cin>>Sword;
	cout<<o.searchword(Sword)<<endl;
	o.remove(Sword);
	cout<<o.searchword(Sword)<<endl;
	  }
