#include<iostream>
#include<cstring>
using namespace std;

bool checkpalindrome(char input[],int start,int end){
	if(input[0]=='\0'||input[1]=='\0'){
		return true;
					}
	if(start>=end){
		return true;
			}
	if(input[start]==input[end]){
		return checkpalindrome(input,start+1,end-1);
				    }
	else{
		return false;
	    }
						}
void replacepi(char input[],int start){
	if(input[start]=='\0' || input[start+1]=='\0'){
		return;
					    }
	replacepi(input,start+1);
    if(input[start]=='p' && input[start+1]=='i'){
	int len=strlen(input);
	input[len+2]='\0';
	for(int i=len-1;i>=start+2;i--){
		input[i+2]=input[i];
					}
	input[start]='3';
	input[start+1]='.';
	input[start+2]='1';
	input[start+3]='4';	
	return;
						}
	}
void removex(char input[],int start){
	if(input[start]=='\0'){
		return;
				}
	removex(input,start+1);
	if(input[start]=='x'){
		int len=strlen(input);
		int i;
		for(i=start+1;i<len;i++){
			input[i-1]=input[i];
					}
		input[i-1]='\0';
		
				}
	return;
					}
int stringtointeger(char input[],int last){
	if(last==0){
		return input[last]-'0';
				}
	int smallans=stringtointeger(input,last-1);
		int a=input[last]-'0';
		return smallans*10+a;
						}
void pairstar(char input[],int start){
	if(input[start]=='\0' || input[start+1]=='\0'){
		return;
							}
	pairstar(input,start+1);
	if(input[start]==input[start+1]){
		int len=strlen(input);
		input[len+1]='\0';
		int i;
		for(i=len-1;i>=start+1;i--){
			input[i+1]=input[i];
					   }
		input[i+1]='*';
					}
		return;
					}
void replacecharacter(char input[],int start,char a,char b){
	if(input[start]=='\0'){
		return;
				}
	replacecharacter(input,start+1,a,b);
	if(input[start]==a){
		input[start]=b;
				}
		return;
								}
void removeduplicates(char input[],int start){
	if(input[start]=='\0' || input[start+1]=='\0'){
		return;
							}
	removeduplicates(input,start+1);
	if(input[start]==input[start+1]){
		int len=strlen(input);
		for(int i=start+2;i<len;i++){
			input[i-1]=input[i];
					    }
		input[len-1]='\0';
					}
	return;
						}
int main(){
	char input[100];
	cin>>input;
	int len=strlen(input);
	//cout<<input[len+10]<<endl;
	/*bool ans=checkpalindrome(input,0,len-1);
	if(ans){
		cout<<"True"<<endl;
		}
	else{
		cout<<"False"<<endl;
	    }*/
	//replacepi(input,0);
	//removex(input,0);
	//pairstar(input,0);
	//char a,b;
	//cin>>a>>b;
	//replacecharacter(input,0,a,b);
	removeduplicates(input,0);
	for(int i=0;input[i]!='\0';i++){
		cout<<input[i];
					}
	cout<<endl;
	//int ans=stringtointeger(input,len-1);
	//cout<<ans<<endl;
	}
