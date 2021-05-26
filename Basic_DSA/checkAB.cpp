#include<iostream>
using namespace std;

bool checkAB(char input[],int start){
	if(input[start]=='\0'){
		return true;
				}
	if(input[start]!='a'){
		return false;
			   }
	if(input[start+1]!='\0' && input[start+2]!='\0'){
		if(input[start+1]=='b' && input[start+2]=='b'){
			return checkAB(input,start+3);
								}
							}
	return checkAB(input,start+1);
				}

int main(){
	char input[100];
	cin>>input;
	bool ans=checkAB(input,0);
	if(ans){
		cout<<"True"<<endl;
		}
	else{
		cout<<"False"<<endl;
	   }
	}
