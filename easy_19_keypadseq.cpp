#include<iostream>
#include<string>
#include <vector>
using namespace std;

string keypadseq(string input, string str[]){
	string output="";

	int n = input.length();
	for(int i=0;i<n;i++){
		if (input[i] == ' ')
            output = output + "0";
 
		else{
			int position=input[i]-'A';
			output += str[position];
		}
	}
	return output;
}

int main(){
	string input="HELLO WORLD";

	string str[]={
				"2","22","222",
				"3","33","333",
				"4","44","444",
				"5","55","555",
				"6","66","666",
				"7","77","777","7777",
				"8","88","888",
				"9","99","999","9999"};

	string ans=keypadseq(input,str);
	for(int i=0;i<ans.length();i++){
		cout<<ans[i];
	}
	cout<<endl;
}

